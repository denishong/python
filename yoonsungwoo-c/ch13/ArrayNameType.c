#include <stdio.h>

int main(void)
{
	int arr[3]={0,1,2};
	printf(" array name : %p\n", arr);
	printf(" first factor: %p\n", &arr[0]);
	printf(" second factor: %p\n", &arr[1]);
	printf(" third factor: %p\n", &arr[2]);

	return 0;
}
