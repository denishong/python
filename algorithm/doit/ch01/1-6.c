#include <stdio.h>

int main(int argc, char* argv[] )
{
	int i=0, n=0;
	int sum=0;

	do{
		printf("n : ");
		scanf("%d", &n);
	}while(n <=0 );

	for(i=1; i <= n; i++)
	{
		sum += i;
	}
	
	printf("sum of 1~%d is : %d. \n", n, sum);

	return 0;
}
