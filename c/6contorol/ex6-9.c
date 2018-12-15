#include <stdio.h>

#define MAX 4
int main(){
	int a,b,c;
	char M='A';

	for(a=1; a<=MAX; a++){
			putchar(M++);
			for(b=0; b<a; b++){
			putchar('*');
			}
		putchar('\n');
	}
	return 0;
}
	
