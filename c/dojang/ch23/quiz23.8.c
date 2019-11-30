#include <stdio.h>

int main()
{

	unsigned long long num1;

	scanf("%lld", &num1);	

	printf("%lld\n", num1 << 20 >> 4);

	return 0;
}
