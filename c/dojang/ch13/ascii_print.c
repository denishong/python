#include <stdio.h>


int main()
{

	int a = 0;

	while(a != 128)
	printf("%c(0x%x)", a++, a++);

	return 0;
}
