#include <stdio.h>

void print_a(void)
{
	printf("Test print a\n");
}


void print_b(void)
{
	printf("Test print b\n");
}

void print_c(void)
{
	printf("Test print c\n");
}

void(*pFunc[4])() = {print_a, print_b, print_c};

int main()
{

	for(int i=0; i<3; i++)
		pFunc[i]();

	return 0;
}
