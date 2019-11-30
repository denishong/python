#include <stdio.h>

int main()
{

	unsigned char num1 = 3;  // 0000 0011
	unsigned char num2 = 24; // 0001 1000
	

	printf("%u\n", num1 << 3);
	printf("%u\n", num2 >> 2);

	return 0;
}
