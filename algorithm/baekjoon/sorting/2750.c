#include <stdio.h>

int main()
{
	int data[1001] = {0,};
	int i,j, size=5;
	int tmp, exchg;


	//input data size
	scanf("%d", &size);

	//input data
	for(i=0; i<size; i++) 
		scanf("%d", &data[i]);

	for(i=0; i<size-1; i++)
	{
        	printf("arrange i: %d, j: %d data[j-1] : %d, data[j] : %d\n", i, j, data[j-1], data[j] );
		for(j=size-1; j>i; j--)
        {
			if(data[j-1] > data[j] )
			{
				tmp = data[j-1];
				data[j-1] = data[j];
				data[j] = tmp;	
			}
        }
	}

	for(i =0; i<size; i++)
		printf("%d\n", data[i] );
		
	return 0;
}
