#include <stdio.h>

int main()
{
    int input[1000000],count=9,i;
	int max=0;

	for(i=0; i< count; i++)
		scanf("%d", &input[i]);

	max = input[0];
	for(i=0; i< count; i++)
		if( input[i] > max) max = input[i];
	
	for(i=0; i< count; i++)
		if( max == input[i] )
		printf("%d %d\n", max, i+1);
   
   return 0;
}
