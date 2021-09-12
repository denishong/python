#include <stdio.h>

int main()
{
    int input[1000000],count,i;
	int min=0, max=0;
    scanf("%d", &count);

	for(i=0; i< count; i++)
		scanf("%d", &input[i]);

	min = input[0];
	max = input[0];
	for(i=0; i< count; i++)
	{
		if( input[i] < min) min = input[i];
		if( input[i] > max) max = input[i];
	}	
		printf("%d %d\n", min, max);
    return 0;
}
