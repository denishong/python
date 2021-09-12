#include <stdio.h>

int main(int argc, char* argv[] )
{
	int i=0, n=0;
	int sum=0;

	scanf("%d", &n);

	for(i=1; i <= n; i++)
	{
		sum += i;
		printf("%d", i);
	}
	
	printf("sum of 1~%d is : %d. \n", n, sum);

	return 0;
}
