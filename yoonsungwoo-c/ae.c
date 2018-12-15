#include <stdio.h>

int main(void)
{

	int a=25,b=-33;

	printf("a=%x b=%x\n", a,b);
	printf("a & b=%d\n", a & b);
	printf("a | b=%d\n", a | b);
	printf("a ^ b=%d\n", a ^ b);
	printf("~(a & b)=%d\n", ~(a & b));

	return 0;
}
