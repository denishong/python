#include <stdio.h>

int main()
{
	int count;
	scanf("%d", &count);

	for(int i=0; i < count; i++)
	{
		for(int j = count -1; j >= 0; j--)
		{
			if(j > i)
				printf(" ");
			else
				printf("*");
		}
		for(int j = 0; j < count-1; j++)
		{
			if(j < i)
				printf("*");
		}
		
		printf("\n");
	}

	return 0;
}
