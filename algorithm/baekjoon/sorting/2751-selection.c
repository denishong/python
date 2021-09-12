#include <stdio.h>
#define swap(type,x,y) do{ type t=x; x=y; y=t; }while(0) 

void selection(int data[], int size)
{

	int i,j;
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
}


int main()
{
	int data[5] = {2,4,5,1,3};
	int i,j, size;
	int tmp;


	//input data size
	//scanf("%d", &size);

	size = sizeof(data)/sizeof(int);

	printf("size : %d\n", size);
	//input data
	//for(i=0; i<size; i++) 
	//	scanf("%d", &data[i]);

	selection(data, size);

	for(i =0; i<size; i++)
		printf("%d\n", data[i] );
		
	return 0;
}
