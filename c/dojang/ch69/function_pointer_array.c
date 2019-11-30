#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
} 

int mul(int a, int b)
{
    return a * b;
} 

int div(int a, int b)
{
    return a / b;
}

int main()
{
    int funcNumber;
    int num1, num2;

	 int (*fp[4])(int, int);

	 fp[0] = add;
	 fp[1] = sub;
	 fp[2] = mul;
	 fp[3] = div;


	 printf("Input function number and numbers to be calculated\n");
    scanf("%d %d %d", &funcNumber, &num1, &num2);


    printf("%d\n", fp[funcNumber](num1, num2));

    return 0;
}
