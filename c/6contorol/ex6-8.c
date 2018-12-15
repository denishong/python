#include <stdio.h>

#define MAX 4
int main(){
	int a,b,c;
	char M='Z';

	for(a=MAX; a>=1; a--){
		for(c=MAX-a; c>=1; c--) putchar(' ');
			for(b=0; b<a; b++){
			putchar(M--);
			}
		putchar('\n');
	}
	return 0;
}
	
