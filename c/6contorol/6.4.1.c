#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, su=2;

	for(i=0; i<100; i++)
	{	
	su=rand();
	switch(su%4)
		{
			case 1: printf("one\n"); break;
			case 2: printf("two\n"); break; 
			case 3: printf("three\n"); break;
		}		
	}

	printf("\n The end program");
	
	return 0;
}
	
