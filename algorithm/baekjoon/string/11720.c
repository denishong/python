#include <stdio.h>
#define MAXN ((int) 1e2)

int main()
{
	int N;
	int A[MAXN+10];
	int total=0;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%1d", &A[i]);
		total += A[i];
	}
	printf("%d\n", total);

	return 0;
}
