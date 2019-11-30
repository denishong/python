#include <stdio.h>

int main()
{

	char i;

	for(i=32; i<127; i++)
		printf("ASCII[%3d] : %c \n", (int)i, i);


	return 0;
}
