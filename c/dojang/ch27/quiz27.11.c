#include <stdio.h>

int main()
{
	char c,c1;

	scanf("%c", &c1);

	for(c = c1; c <= 'z'; c++)
		printf("%c", c);

	return 0;
} 
