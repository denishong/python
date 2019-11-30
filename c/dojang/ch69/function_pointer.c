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

	 int (*f)(int, int) = NULL;

	printf("Input function number and numbers to be calculated\n");
    scanf("%d %d %d", &funcNumber, &num1, &num2);


	switch (funcNumber)
	{
	case 0:
		f = add;
		break;
	case 1:	
		f = sub;
		break;	
	case 2:	
		f = mul;
		break;	
	case 3:	
		f = div;
		break;	
 	} 
    printf("%d\n", f(num1, num2));

    return 0;
}
