#include <stdio.h>

int main(void)
{
	int num1=0xA7, num2=0x43;
	int num3=032, num4=024;

	printf("0xA7 decimal value: %d \n", num1);
	printf("0x43 decimal value: %d \n", num2);
	printf("032 decimal value: %d \n", num3);
	printf("024 decimal value: %d \n", num4);


	printf("%d-%d=%d \n", num1, num2, num1-num2);
	printf("%d+%d=%d \n", num1, num2, num1+num2);

	return 0;
}
