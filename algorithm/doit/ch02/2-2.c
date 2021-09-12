#include <stdio.h>

int main(int argc, char* argv[] )
{
	int i;
	int a[] = {1,2,3,4,5};
	int na = sizeof(a) / sizeof(int);

	for(i =0; i < na; i++){
		printf("a[%d] = %d\n",i, a[i] );
	}

	return 0;
}
