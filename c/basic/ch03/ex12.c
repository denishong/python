#include <stdio.h>

int main()
{
	float a,b;
	a = 12.6;
	b = (int) a + (int) 12.8;

	printf("%f\n", b);

	b = (int)(a + 12.8);
	printf("%f\n", b);

	return 0;
}
