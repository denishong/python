#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[] )
{
	int* x;
	x = calloc(1, sizeof(int));

	if(x == NULL){
		puts(" fail to alloc memory.");
	}else{
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);
	}

	return 0;
}
