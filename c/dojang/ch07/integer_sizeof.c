#include <stdio.h>

int main()
{
	int num1 = 0;

	printf("integer size : %d\n", (int)sizeof(int));
	printf("char size : %d\n", (int)sizeof(char));
	printf("unsigned integer size : %d\n", (int)sizeof(unsigned int));
	printf("long size : %d\n", (int)sizeof(long));
	printf("integer size : %d\n", (int)sizeof(num1));

	return 0;
}
