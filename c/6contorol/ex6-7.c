#include <stdio.h>

#define MAX 4
int main(){
	int a,b;
	char M='A';

	for(a=1; a<=4; a++){
			for(b=0; b<a; b++){
			putchar(M++);
			}
		putchar('\n');
	}
	return 0;
}
	
