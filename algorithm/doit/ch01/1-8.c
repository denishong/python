#include <stdio.h>

int main(int argc, char* argv[] )
{
	int i, j, n;


	do{
		printf(" How many multiangle? \n");
		scanf("%d", &n);
	}while(n <= 0);

	for(i =1; i <=n; i++){
		for(j =1; j <= i; j++){
			printf("*");
		}
	printf("\n");
	}

	return 0;
}
