#include <stdio.h>

int main(){

	int a=1,b;

	do{
		for(b=1;b<=a; b++)
			printf("%c",b+64);
		putchar('\n');
		a++;
	}while(a<=6);
	printf("program end.\n");

 return 0;
}
