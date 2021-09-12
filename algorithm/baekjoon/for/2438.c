#include <stdio.h>

int main()
{
    int A,B, repeat;
	int i,j;
    scanf("%d", &repeat);

	for( i=1; i<=repeat; i++)
	{
		for(j=1; j<=i; j++)
    		printf("*");

    		printf("\n");
	}
    return 0;
}
