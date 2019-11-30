#include <stdio.h>
int main()
{
	int a[5] = {1,2,3,4,5};

	int *p = &a[4];

	int index = p - a;

	printf("index=%d\n", index );
	printf("main=%p\n", main);
	return 0;
}
