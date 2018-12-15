#include <stdio.h>

int main(void)
{
	int num1,num2,num3;

	printf("정수 one: \n");
	scanf("%d",&num1);
	printf("정수 two: \n");
	scanf("%d",&num2);
	printf("정수 three: \n");
	scanf("%d",&num3);

	printf("%d * %d + %d =%d \n", num1,num2,num3,num1*num2+num3);

	return 0;
}
