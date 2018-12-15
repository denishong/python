#include <stdio.h>

int main(){

	int a=1;

	while(a<=10){
		printf("%d=",a);
		if(a%2==0)printf("even number");
		else printf("odd number");
		printf(" is\n");
		a++;
	}
	printf("program end");
	return 0;
}
