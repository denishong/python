#include <stdio.h>
#include <stdlib.h>

int search(const int a[],int  n, int key)
{
    int i ;
	while(1)
    {
		if( i==n )
			return -1;
		if(a[i] == key)
			return i;
		i++;
	}
}

int main(void)
{

	int x[10]={6,4,3,2,1,3,8};
	int i=0,n, key;

	n = sizeof(x)/sizeof(int);

	printf(" search value? \n");
	scanf("%d", &key);

    i = search(x, n, key);
	printf("index : %d \n", i);
	return 0;
}
