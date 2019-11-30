#include <stdio.h>

void hello()
{
	printf("Hello, world!\n");
	hello();
}

int main()
{
	hello();
	return 0;
}
