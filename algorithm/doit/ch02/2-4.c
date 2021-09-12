#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[] )
{
	int i;
	int* a;
	int na;

	printf("number of factors: ");
	scanf("%d", &na);
	a = calloc(na, sizeof(int));

	if(a == NULL){
		puts(" fail to alloc memory.");
	}else{
		printf("%d input numbers: \n", na);
		for(i = 0; i < na; i++){
			printf("a[%d] :  ", i);
			scanf("%d", &a[i]);
		}
		
		printf("factors are here. \n");
		for(i=0; i < na; i++)
			printf("a[%d] = %d\n", i , a[i]);

		free(a);
	}

	return 0;
}
