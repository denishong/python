#include <stdio.h>

int main(){

	int a=1;

	while(a<=10){
		if(a%2==1)printf("%d",a);
		a++;
	}
	printf("program end");
	return 0;
}
