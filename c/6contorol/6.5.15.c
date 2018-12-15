#include <stdio.h>


int main(){

	int a,b,c=100;

	for(a=1; a<=2; a++)
		for(b=1; b<=3; b++){
			c+=10;
			printf("%d\n",c);
		}
	printf("\n program running end");

	return 0;
}
