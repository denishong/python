#include <stdio.h>

int main()
{
	int input,repeat,i,j,A;
    scanf("%d %d", &repeat, &A);

	for( i=0; i<repeat; i++)
	{
		scanf("%d", &input);
			printf("i : %d ", i);
		if( input < A)
			printf("%d ", input);
	}

    return 0;
}
