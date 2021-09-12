#include <stdio.h>

int main()
{
    int A;
    scanf("%d", &A);

	if ( (90 <= A) && (A <= 100) )
	{
    	printf("A\n");
	}
	else if ( (80 <= A) && (A <= 89) )
	{
    	printf("B\n");
	}
	else if ( (70 <= A ) && ( A <= 79) )
	{
    	printf("C\n");
	}
	else if ( (60 <= A ) && ( A <= 69) )
	{
    	printf("D\n");
	}
	else 
	{
    	printf("F\n");
	}

    return 0;
}
