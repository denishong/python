#include <stdio.h>

#define MAX 4
int main(){

	int a,b,c;

	for(a=MAX; a>=1; a--){
		for(b=MAX-a; b>0; b--)
		 putchar(' ');
			for(c=0; c<a; c++){
			putchar('*');
			}
		putchar('\n');
	}
	return 0;
}
	
