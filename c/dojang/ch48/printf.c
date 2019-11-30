#include <stdio.h>

void print_card(char *name)
{
	printf("print_card name : %s \n", name);
}

int main()
{
	char *name ="name";

	printf("name : %s\n", name );

	print_card((char *)name);

	return 0;
}
