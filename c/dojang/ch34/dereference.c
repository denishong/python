#include <stdio.h>

int main()
{
	int *num1pointer;
	int num1 = 10;

	num1pointer = &num1;

	*num1pointer = 20;
 

	printf("%d\n", *num1pointer);
	printf("%d \n", num1);

	return 0;
}
