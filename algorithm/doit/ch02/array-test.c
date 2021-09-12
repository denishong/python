#include <stdio.h>

int main()
{

#if 0
	int a[][2] = {
		{55, 185},
		{58, 183},
		{88, 186},
		{60, 175},
		{46, 155}};
#endif
	int a[5][2] = {};
	int i,j,n;
	scanf("%d", &n);

	for(i=0; i<5; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("i:%d j:%d \n", i,j);
			scanf("%d ",&a[i][j]);
		}
	}

	for(i=0; i<n; i++)
	{
		for(j=0; j<2; j++)
		printf("a[%d][%d] : %d ", i, j, a[i][j]);
		printf("\n");
	}
	return 0;
}
