#include<stdio.h>

int main(void)
{
	char M;
	int i;
	M=64;

	for(i=0; i<10; i++){	
	we: M++;
	putchar(M);
	if(M!=90) goto we;
	M=64;
	printf("\n");
	}

	return 0;
}
