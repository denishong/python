#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int num)
{
	if( num == 0)
		return 0;
	if( num == 1 || num == 2)
		return 1;

	return fib(num -2) + fib(num -1);
}

int main()
{
    int num1;

    scanf("%d", &num1);

    printf("%d\n", fib(num1));

    return 0;
}
