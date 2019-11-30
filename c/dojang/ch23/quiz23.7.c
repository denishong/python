#include <stdio.h>

int main()
{

	unsigned int num1;
	unsigned int num2;

	scanf("%u", &num1);	
	scanf("%u", &num2);	

	printf("%u\n", num1 ^ num2);
	printf("%u\n", num1 | num2);
	printf("%u\n", num1 & num2);
	printf("%u\n", ~num1);

	return 0;
}
