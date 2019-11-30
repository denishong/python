#include <stdio.h>

int main()
{
	int *num1pointer;
	int num1 = 10;

	num1pointer = &num1;

	printf("%p %d\n", num1pointer,sizeof(int *));
	printf("%p \n", &num1);
	printf("%d \n", sizeof(char));
	printf("%d \n", sizeof(char *));

	return 0;
}
