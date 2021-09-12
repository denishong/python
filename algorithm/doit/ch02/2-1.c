#include <stdio.h>

#define N 5
int main(int argc, char* argv[] )
{
	int i;
	int a[N];

	for(i =0; i < N; i++){
		printf("a[%d] : ",i);
		scanf("%d", &a[i] );
	}

	for(i =0; i < N; i++){
		printf("a[%d] = %d\n",i, a[i] );
	}

	return 0;
}
