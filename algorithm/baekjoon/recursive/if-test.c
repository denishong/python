#include <stdio.h>

int factorial(int a)
{
	if(a > 2){
		
		return a*factorial(a-1);
	}
}


int main()
{
    int i,repeat;
	int fact=1; 
    scanf("%d", &repeat);
	
	if( repeat > 5)
		printf("%d\n", repeat );
	printf("Test\n");

    return 0;
}
