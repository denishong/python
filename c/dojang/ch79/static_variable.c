#include <stdio.h>

void increaseNumber()
{
	static int num = 0;
	printf("%d\n", num);
	num++;
}

int main()
{
	increaseNumber();
	increaseNumber();
	increaseNumber();
	increaseNumber();
	increaseNumber();

	return 0;
}
