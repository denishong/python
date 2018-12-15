#include <stdio.h>

int main(void)
{
	int i=0,j=0;
	int start=0,end=0;

	printf("start value : ");
	scanf("%d", &start);
	printf("\n");
	printf("end value : ");
	scanf("%d", &end);

	printf("start :%d end:%d\n", start,end);	

	for(i=start; i<=end; i++)
	{
		j+=i;
	}

	printf("sum : %d\n",j);

	return 0;
}

