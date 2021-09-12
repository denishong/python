#include <stdio.h>

int main()
{
	int i,j,k,repeat;
    scanf("%d", &repeat);

	for( i=1; i<=repeat; i++)
	{
		for(k=1; k<=repeat-i; k++)
			printf(" ");
			for(j=1; j<=i; j++)
    			printf("*");

    		printf("\n");
	}
    return 0;
}
