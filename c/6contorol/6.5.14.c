#include <stdio.h>

int main()
{

	int a,b;

	printf("<< multi for loop >>\n");
	for(a=1; a<=3; a++)
		for(b=1; b<=3; b++)
			printf("a=%d b=%d\n", a,b);

	printf("\n program end.");

	return 0;
}
