#include <stdio.h>


int main()
{

	int a,i=0;

	while(i<10)
	{
		++i;
		a += i;
		printf("%d \n", a);
	}

	printf("%d \n", a);


	return 0;
}
