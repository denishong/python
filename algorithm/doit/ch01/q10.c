#include <stdio.h>

int main(int argc, char* argv[] )
{
	int a, b;

	printf("a : ");
	scanf("%d", &a);

	do{
		printf("b : ");
		scanf("%d", &b);
		printf("please input more than a \n");
	}while( b < a );

	printf("b - a is : %d. \n", b-a);

	return 0;
}
