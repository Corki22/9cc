#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
	if (argc!=2){
		fprintf(stderr,"the number of argument is not correct\n");
		return 1;
	}

	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");
	printf(" mov rax, %d\n", atoi(argv[1]));
	printf(" ret\n");
	return 0;
}
<<<<<<< HEAD
=======
//test
>>>>>>> 39deb06a07cc717799f50e71668b67e6e9305d81
