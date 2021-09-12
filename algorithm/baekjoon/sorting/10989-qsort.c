#include <stdio.h>
#include <stdlib.h>

int int_cmp( const int *a, const int *b)
{

	if(*a < *b)
		return -1;
	else if(*a > *b)
		return 1;
	else 
		return 0;
}

int main()
{
//	int a[10] = {5,2,3,1,4,2,3,5,1,7};
//	int a[10000001] = {0,};
	int *a;
	int i,j, size;
	int tmp;


	//input data size
	scanf("%d", &size);
	a = calloc(size, sizeof(int));
//	size = sizeof(a)/sizeof(int);

	//printf("size : %d\n", size);
	//input data
	for(i=0; i<size; i++) 
		scanf("%d", &a[i]);

	qsort(a,  size, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	for(i =0; i<size; i++)
		printf("%d\n", a[i] );
		
	free(a);
	return 0;
}
