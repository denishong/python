#include <stdio.h>

int main()
{
	int a,b,c,d;

	a = 5; b =5;

	c=a--; d=--b;

	printf("%d %d %d %d\n",a, b,c,d);


	a = 5;
	c = --a;
	printf("%d %d\n",a, c);
}

