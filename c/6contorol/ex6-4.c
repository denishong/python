#include <stdio.h>

int main(){

	int a=4,b;

	for(a=4; a>=1; a--){
		for(b=0; b<a; b++){
		putchar('*');
	}
		putchar('\n');
	}
	return 0;
}
	
