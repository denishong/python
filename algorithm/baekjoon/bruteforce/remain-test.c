#include <stdio.h>


int main()
{
	int a;
	scanf("%d", &a);

	printf("1 : %d\n", a%10);
	printf("10 : %d\n", (a%100)/10);
	printf("100 : %d\n", (a%1000)/100);
	return 0;
}
