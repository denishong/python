#include <stdio.h>

int main(void)
{
	int arr1[3][4];
	int arr2[7][9];

	printf("vertical :3 horizental :4 %d",(int) sizeof(arr1));
	printf("vertical :7 horizental :9 %d", (int) sizeof(arr2));

	return 0;
}
