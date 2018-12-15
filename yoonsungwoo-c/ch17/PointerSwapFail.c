#include <stdio.h>

void SwapIntptr(int *p1, int *p2)
{
	int  tem=*p1;
	printf("*p1, *p2 : %d %d \n", *p1, *p2);
	printf("p1, p2 : %p %p \n", p1, p2);
	*p1=*p2;
	*p2=tem;
	printf("*p1, *p2 : %d %d \n", *p1, *p2);
	printf("p1, p2 : %p %p \n", p1, p2);
}
int main(void)
{
	int num1=10, num2=20;
	int *ptr1, *ptr2;
	ptr1=&num1, ptr2=&num2;

	printf("*ptr1, *ptr2 : %d %d \n", *ptr1, *ptr2);
	printf("ptr1, ptr2 : %p %p \n", ptr1, ptr2);

	SwapIntptr(ptr1, ptr2);
	printf("num1, num2: %d %d \n", num1, num2);
	printf("*ptr1, *ptr2 : %d %d \n", *ptr1, *ptr2);


return 0;
}
