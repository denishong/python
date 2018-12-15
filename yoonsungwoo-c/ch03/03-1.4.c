#include <stdio.h>

int main(void)
{
	int num1,num2,num3;

	printf("정수 one: \n");
	scanf("%d",&num1);
	printf("정수 two: \n");
	scanf("%d",&num2);

	printf("%d/%d의 몫  =%d \n", num1,num2,num1/num2);
	printf("%d/%d의 나머지  =%d \n", num1,num2,num1%num2);

	return 0;
}
