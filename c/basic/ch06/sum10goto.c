#include <stdio.h>


int main()
{

	int a = 0,i=0;

sum:
		++i;
		a += i;

	if(i<10) goto sum;
	printf("%d \n", a);


	return 0;
}
