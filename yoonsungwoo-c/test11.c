#include <stdio.h>

int main()
{
	int num1 = 100;
	int num2 = 200;
	int num3 = 300;
	int *ptr[3] = {&num1, &num2, &num3};
	int **pptr;

	pptr = ptr;

	printf("%d\n", *(*(pptr + 1)));
	printf("%d\n", **(pptr + 1));
	printf("%d\n", *(ptr + 1));
	printf("%d\n", num2);   

	return 0;
}
