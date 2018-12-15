#include <stdio.h>

int main(void)
{

	int num1=15;
	int num2=20;
	int num3= num1 & num2;
	int i;

	printf("AND operation result: %d \n", num3);
	for(i=0; i<6; i++)
	printf("15 1bit left shift: %b \n", num1<<i);

	return 0;
}
