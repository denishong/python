#include <stdio.h>

int main()
{
	int i ;
	scanf("%d", &i);

	while(i >= 1200)
	{
		i -= 1200;
		printf("%d\n", i);
	}

	return 0;
}
