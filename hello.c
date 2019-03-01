#include<stdio.h>


int one(){
	return 1;
}

int two(){
	return 2;
}

int add(int iti,int ni){
	int ans=iti+ni;
	return ans;
}

int
main(void)
{
int	ans=add(one(),two());
	printf("%d\n",ans);

	return 0;
}
