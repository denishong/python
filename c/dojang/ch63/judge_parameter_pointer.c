#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getQuotientAndRemainder(int num1, int num2, int *r)
{
	*r = num1 % num2;
	return num1 / num2;
}


int main()
{
    int num1;
    int num2;
    int quotient;     // 몫
    int remainder;    // 나머지

    scanf("%d %d", &num1, &num2);

    quotient = getQuotientAndRemainder(num1, num2, &remainder);

    printf("%d %d\n", quotient, remainder);

    return 0;
}
