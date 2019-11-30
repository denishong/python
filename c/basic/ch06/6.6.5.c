#include <stdio.h>

int main(){

	int a=50,b=5;

	while(b>=3){
		a+=50;
		b--;
		printf("a=%d b=%d\n",a,b);
	}

	printf("program end");
	return 0;
}
