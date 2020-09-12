#include <stdio.h>

int main(int argc, char *argv[])
{

	int i = 0;
	int sum = 0;
	printf("add!!\n");

	if( argc == 1)
		printf("error input argument!!\n");

	for( i=0; i<argc; i++)
		printf(" argv[%d] : %d\n", i, argv[i]);
		//sum += argv[i];
	
	printf("sum : %d\n", sum);
		
	return 0;
}
