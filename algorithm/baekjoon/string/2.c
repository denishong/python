#include <stdio.h>



int swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a= *b;
	*b = temp;
}
int main()
{
	int total=0;
	int *num1, *num2;
    scanf("%m[0-9] %m[0-9]",num1, num2);


    printf("num1: %d num2: %d\n",*num1, *num2 );

	swap(num1,num2);
    printf("num1: %d num2: %d\n",*num1, *num2 );

    return 0;
}
