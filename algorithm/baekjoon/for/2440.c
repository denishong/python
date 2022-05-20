#include <stdio.h>

int main()
{
    int i,j,repeat; 
    scanf("%d", &repeat);
	for( i=0; i<repeat; i++)
	{
		for(j=0; j<repeat-i; j++)
				printf("*");

		printf("\n");
	}
	return 0;
}
