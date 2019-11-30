#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num1;
    int num2;
    int i;

    
    i = 1;

	for(i = 1; i<20; i++)
	{
		if(i%7==0)
		continue;
		printf("%d\n",i);
	}

    return 0;
}
