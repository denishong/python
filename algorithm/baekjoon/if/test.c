#include <stdio.h>

int main()
{
    int A,B;
    scanf("%d", &A);

	if (0 <A && A < 10)
    printf("0 ~ 10\n");
	else if (10 < A)
    printf("10 이상\n");

    return 0;
}
