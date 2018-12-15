#include <stdio.h>

int main()
{
	int i, j;
	int nums[10] = {1, 5, 7, 2, 6, 4, 3, 9, 8, 0};
	int temp = 0;

	printf("nums: ");
	for (i = 0; i < 10; i++)
		printf("%d ", nums[i]);
	printf("\n");

	for (i = 1; i < 10; i++) {
		for (j = 0; j < 10 - i; j++) {


if (nums[j] > nums[j + 1]) {
	    	temp = nums[j];
        	nums[j] = nums[j + 1];
        	nums[j + 1] = temp;
        }

}
	}

	printf("sorted_nums: ");
	for (i = 0; i < 10; i++)
		printf("%d ", nums[i]);
	printf("\n");

	return 0;
}
