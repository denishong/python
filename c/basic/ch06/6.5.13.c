#include <stdio.h>

int main()
{

	int a,b;
	
	for(a=1,b=200; a<=3; a++,b-=50)
		printf("a=%d b=%d\n", a,b);

	printf("\n program end.");

	return 0;
}
