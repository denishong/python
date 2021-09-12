#include <stdio.h>

int main()
{
    int count,i;
	float total=0,max; 
	float subject[1010]={0};
    scanf("%d", &count);

	for(i=0; i<count; i++)
			scanf("%f", &subject[i]);
	
		max = subject[0];
		for(i=0; i<count; i++)
		{
				if( max < subject[i+1])
						max = subject[i+1];
		}

	for(i=0; i<count; i++)
		total += ((subject[i]*100)/max);
				
		printf("%10.6f\n", (float)total/count );
	return 0;
}
