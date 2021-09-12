#include <stdio.h>

int main()
{
    int A,B, repeat;
    scanf("%d", &repeat);

	for( i=1; i<=repeat; i++)
	{
    	scanf("%d %d", &A, &B);
    	printf("Case #%d: %d + %d = %d\n", i, A,B, A+B);
	}
    return 0;
}
