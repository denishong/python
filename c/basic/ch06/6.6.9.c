#include <stdio.h>

int main(){

	int a=1,b;

	while(a<=10){
			for(b=1; b<=a; b++)
				printf("%d",b);
			putchar('\n');
			a++;
	}

	printf("program end");

	return 0;

}
