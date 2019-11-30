#include <stdio.h>

int main()
{	
	int num1 = 10;
	int *numPtr1;
	int **numPtr2;

	numPtr1 = &num1;
	numPtr2 = &numPtr1;

	printf("%d num1 : %p\n", num1,&num1);
	printf("%d numPtr1 : %p\n", *numPtr1,numPtr1);
	printf("%d numPtr2 : %p\n", **numPtr2,numPtr2);
	printf("%d \n", (int)sizeof(int));
	printf("%d \n", (int)sizeof(int *));
	printf("%d \n", (int)sizeof(char *));
	printf("%d \n", (int)sizeof(long long *));
	printf("%d \n", (int)sizeof(float *));

	return 0;
}
