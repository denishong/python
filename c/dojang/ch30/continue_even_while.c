#include <stdio.h>

int main()
{
	int count;
	scanf("%d", &count);

	 int i = 1; 
	while(1)
	{
		if(i > count)
			break;

		if (i%2 !=0)
		{
			i++;
			continue;
		}
		printf("%d\n", i);
		i++;
	}

	return 0;

} 
