#include <stdio.h>

int main()
{
	//int a[2][5] = { {1,2,3,4,5}, {6,7,8,9,10} };
	//int a[2][5] = { 1,2,3,4,5, 6,7,8,9,10 };
	int a[5][2] = { {1,2},{3,4},{5, 6},{7,8},{9,10} };
	int i,j;
	int n = sizeof(a) / sizeof(int);
	printf("n : %d\n", n);

	for(i=0; i<5; i++)
	{
		for(j=0; j<2; j++)
		printf("a[%d][%d] : %d ", i, j, a[i][j]);
		printf("\n");
	}
	return 0;
}
