#include <stdio.h>

int check[10];

int main()
{

	for(int i =0; i < 10; i++){
		
		if(i ==5){
		check[i]++;
		}
	//	printf("check test %d \n", check[i]);
	}


	for(int i =0; i < 10; i++)
		printf("check test %d \n", check[i]);

	return 0;
}
