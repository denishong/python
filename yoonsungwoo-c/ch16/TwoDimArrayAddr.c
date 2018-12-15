#include <stdio.h>

int main(void)
{
	int arr[3][2]=
	{
		{1,2},
		{2,5},
		{4,2}
	};
	int i,j;
	for(i=0; i<3; i++)
		for(j=0;j<2;j++)
		{
			printf("%p \n", &arr[i][j]);
			printf("%d \n", arr[i][j]);
		}
	return 0;
}
