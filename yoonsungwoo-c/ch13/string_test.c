#include <stdio.h>

int main(void)
{
	int i = 0;
	char* string = "TEST";

	while(*(string + i) != ' ')
	{
		printf("test string : %c\n", *(string + i) );
		i++;
	}
	return 0;
} 
