#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

	if ( (0 < A ) && (0 < B ) )
	{
    	printf("1\n");
	}
	else if ( (0 > A ) && (0 < B ) )
	{
    	printf("2\n");
	}
	else if ( (0 > A ) && (0 > B ) )
	{
		printf("3\n");
	}
	else if ( (0 < A ) && (0 > B ) )
	{
		printf("4");
	}

    return 0;
}
