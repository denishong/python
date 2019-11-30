#include <stdio.h>

int main(){

	int a=1;

	while(a<=10)
	{
		printf("%d=",a);
		if(a%3==0){
			printf("This is");
			printf("3th multiple number.\n");
		}else 
			printf("Well! this is not 3th multiple number\n");
			a++;
		}
	return 0;
}
