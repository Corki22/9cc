#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	int ty;
	int val;
	char *input;
}Token;

typedef struct{
	int ty;
	struct Node *lhs;
	struct Node *rhs;
	int val;
}Node;

extern Token tokens[100];
extern int pos;

int Consume(int ty);

void Tokenize(char *p);

void error(int i);

Node *NewNode(int ty, Node *lhs, Node *rhs);

Node *NewNodeNum(int val);

Node *Num();

Node *Add();

Node *Mul();

Node *Term();

void Gen(Node *node);


