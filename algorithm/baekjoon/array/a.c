#include <stdio.h>


int main()
{
	int i, n;
	int a[] = {1,2,3,4,5};

	n = sizeof(a)/sizeof(a[0]);

	for(i=0; i<n; i++)
		printf("a[%d] : %d\n",i, a[i]);

	return 0;
}
