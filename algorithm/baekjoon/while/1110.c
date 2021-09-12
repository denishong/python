#include <stdio.h>

int main()
{
    int input,a,b, new_value,i=0;

    scanf("%d", &input);
	a = input;
	while(1 )
	{
		new_value = (a/10) + (a%10);
		b = (a%10)*10 + new_value%10;
		if( input !=b)
		{
			a = b;
			i++;
		} else{
			i++;
			printf("%d\n",i);
			break;
		}
	}

	
    return 0;
}
