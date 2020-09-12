#include <stdio.h>

int main(void)
{

	int *num;

	printf("size of int pointer %ld\n", sizeof(num));
	printf("size of char pointer %ld\n", sizeof(char*));
	printf("size of char %ld\n", sizeof(char));
	printf("size of int %ld\n", sizeof(int));
	printf("size of int %ld\n", sizeof(int*));
	printf("size of int %ld\n", sizeof(long *));
	printf("size of int %ld\n", sizeof(double *));

	return 0;
}
