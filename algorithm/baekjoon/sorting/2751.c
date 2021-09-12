#include <stdio.h>
#define swap(type,x,y) do{ type t=x; x=y; y=t; }while(0) 


for(i=0; i<size-1; i++)
	{
        int min = i;
		for( j=i+1; j<size; j++ )
		{
//        	printf("arrange i: %d, j: %d data[j-1] : %d, data[j] : %d\n", i, j, data[j-1], data[j] );
			if( data[j] < data[min] )
			{
                min = j;
			}
		}
                swap(int, data[i], data[min] );
	}

int main()
{
	int data[1000001] = {0,};
	int i,j, size;
	int tmp;


	//input data size
	scanf("%d", &size);

	//input data
	for(i=0; i<size; i++) 
		scanf("%d", &data[i]);

	for(i=0; i<size-1; i++)
	{
        int min = i;
		for( j=i+1; j<size; j++ )
		{
//        	printf("arrange i: %d, j: %d data[j-1] : %d, data[j] : %d\n", i, j, data[j-1], data[j] );
			if( data[j] < data[min] )
			{
                min = j;
			}
		}
                swap(int, data[i], data[min] );
	}

	for(i =0; i<size; i++)
		printf("%d\n", data[i] );
		
	return 0;
}
