#include <stdio.h>

int main()
{
	char *a;
	char *b;
	char *c;
	char *d;
	char i,j,k,l;


	a = &i;
	b = &j;
	c = &k;
	d = &l;

	printf("a address : %p\n", a);
	printf("b address : %p\n", b);
	printf("c address : %p\n", c);
	printf("d address : %p\n", d);
	printf("*a address : %p\n", &*a);
	return 0;
}
