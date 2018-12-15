#include <stdio.h>

int main(void)
{
	int i;
	int max,min,sum;
	int arr1[5];


	for(i=0; i<5; i++)
		scanf("%d ", &arr1[i]);

	for(i=0; i<5; i++)
		printf("%d ", arr1[i]);

   min=max=arr1[0];

	for(i=0;i<5; i++)
	{
		sum+=arr1[i];
		if(max<arr1[i])		
		max=arr1[i];
		
		if(min>arr1[i])		
		min=arr1[i];
	}

	printf("min :%d, max :%d, sum :%d \n", min,max,sum);
	return 0;
}
