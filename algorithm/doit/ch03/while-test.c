#include <stdio.h>

int main(void)
{

	int x[]={6,4,3,2,1,3,8};
	int i=0,n, key;

	n = sizeof(x)/sizeof(int);

	while( i < n){
		printf("x[%d] : %d\n", i, x[i]);
		i++;
		if( x[i] == 3)
		break;
	}

	printf("index : %d \n", i);
	return 0;
}
