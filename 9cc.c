#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


enum{
	TK_NUM=256,
	TK_EOF,
};

typedef struct{
	int ty;
	int val;
	char *input;
}Token;

typedef struct Node{
	int ty;
	struct Node *lhs;
	struct Node *rhs;
	int val;
}Node;

Token tokens[100];
int pos=0;

int Consume(int ty){
	if(tokens[pos].ty != ty)
		return 0;
	pos++;
	return 1;
}

Node* Add();

void Tokenize(char *p){
	int i=0;
	while(*p){
		if(isspace(*p)){
				p++;
				continue;
		}	

		if(*p=='+'|| *p=='-' || *p=='*' || *p=='/' || *p=='(' || *p==')'){
			tokens[i].ty=*p;
			tokens[i].input=p;
			i++;
			p++;
			continue;
		}


		if(isdigit(*p)){
			tokens[i].ty=TK_NUM;
			tokens[i].input=p;
			tokens[i].val=strtol(p,&p,10);
			i++;
			continue;
		}

		fprintf(stderr,"incorrect token: %s\n",p);
		exit(1);
	}

	tokens[i].ty=TK_EOF;
	tokens[i].input=p;
}

void error(int i){
	fprintf(stderr, "unexpected token: %s\n",tokens[i].input);
	exit(1);
}

Node *NewNode(int ty, Node* lhs, Node* rhs){
	Node *node =malloc(sizeof(Node));
	node->ty=ty;
	node->lhs=lhs;
	node->rhs=rhs;
	return node;
}

Node *NewNodeNum(int val){
	Node *node=malloc(sizeof(Node));
	node->ty=TK_NUM;
	node->val=val;
	return node;
}

Node *Num(){
	if(tokens[pos].ty==TK_NUM){
		return NewNodeNum(tokens[pos++].val);
	}
	error(pos);
}

Node *Term(){
	if(Consume('(')){
		Node *node=Add();
		if(!Consume(')'))
			printf("there is a no counter ')': %s",tokens[pos].input);
		return node;
	}
	if(tokens[pos].ty==TK_NUM){
		return NewNodeNum(tokens[pos++].val);
	}
	error(pos);
}

Node *Mul(){
	Node *node=Term();
	for(;;){
		if(Consume('*'))
			node=NewNode('*',node,Term());
		else if(Consume('/'))
			node=NewNode('/',node,Term());
		else
			return node;
	}
}

Node *Add(){
	//Creating first node. It must be num
	Node *node=Mul();
	while(1){
		if(Consume('+'))
			node=NewNode('+',node,Mul());
		else if (Consume('-'))
			node=NewNode('-',node,Mul());
		else
		return node;
	}
}


void Gen(Node *node){
	if(node->ty==TK_NUM){
		printf("  push %d\n",node->val);
		return;
	}

	Gen(node->lhs);
	Gen(node->rhs);
	printf("  pop rdi\n");
	printf("  pop rax\n");

	switch(node->ty){
		case '+':
			printf("  add rax, rdi\n");
			break;
		case '-':
			printf("  sub rax, rdi\n");
			break;
		case '*':
			printf("  mul rdi\n");
			break;
		case '/':
			printf("  mov rdx, 0\n");
			printf("  div rdi\n");
	}
	printf("  push rax\n");
}




int main(int argc, char **argv){
	if (argc!=2){
		fprintf(stderr,"the number of argument is not correct\n");
		return 1;
	}

	Tokenize(argv[1]);
	Node *node = Add();

	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");

	Gen(node);

	printf("  pop rax\n");
	printf("  ret\n");
	return 0;
}
