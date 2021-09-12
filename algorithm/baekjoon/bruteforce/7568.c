#include <stdio.h>

int main()
{
	int i,j,n;
	int body[51][2];

	scanf("%d", &n);

	for(i=0; i<n; i++)
		for(j=0; j<2; j++)
			scanf("%d", &body[i][j]);


	printf("\n");

	for(i=0; i<n; i++)
	{
		int rank=1;
		for(j=0; j<n; j++){
		if( body[i][0] < body[j][0] && body[i][1] < body[j][1])
			rank++;
		}
		printf("%d ", rank);
	}

	return 0;
}
