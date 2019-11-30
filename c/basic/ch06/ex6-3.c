#include <stdio.h>

int main(){

	int a=1,b;
	
	for(a=1; a<=4; a++){
		for(b=0; b<a; b++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
