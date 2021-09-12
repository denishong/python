#include <stdio.h>
#define swap(type,x,y) do{ type t=x; x=y; y=t; }while(0) 

void quick(int a[], int left, int right)
{

	int pl = left;
	int pr = right;
	int x = a[(pl + pr)/2];


	int i;
	printf("a[%d]~a[%d] : {", left, right);
	for(i=left; i < right; i++)
		printf("%d", a[i]);
	printf("%d}\n", a[right]);

	do{
		while(a[pl] < x ) pl++;
		while(a[pr] > x ) pr--;

		if(pl <= pr){
			swap(int, a[pl], a[pr] );
			pl++;
			pr--;
		}
	}while(pl <= pr);

	if(left < pr) quick(a, left, pr);
	if(pl < right) quick(a, pl, right);
}


int main()
{
	int a[5] = {2,4,5,1,3};
//	int a[10000001] = {0,};
	int i,j, size;
	int tmp;


	//input data size
	//scanf("%d", &size);

	size = sizeof(a)/sizeof(int);

	printf("size : %d\n", size);
	//input data
//	for(i=0; i<size; i++) 
//		scanf("%d", &a[i]);

	quick(a, 0,  size-1);

	for(i =0; i<size; i++)
		printf("%d\n", a[i] );
		
	return 0;
}
