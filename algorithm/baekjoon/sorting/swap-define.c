#include <stdio.h>
//#define swap(t,x,y) do{ t=x; x=y; y=t; }while(0) 
#define swap(type,x,y) do{ type t=x; x=y; y=t; }while(0) 

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
                swap(int, data[j-1], data[j] );
			}
        }
	}

	for(i =0; i<size; i++)
		printf("%d\n", data[i] );
		
	return 0;
}
