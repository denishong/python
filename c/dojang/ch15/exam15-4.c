#include <stdio.h>

int main()
{

	int num1;

	scanf("%d\n", &num1);

	while(num1 != 0)
	{
		printf("%d ", num1 % 10);
		num1 /= 10;
	}
	putchar('\n');
	return 0;
}
