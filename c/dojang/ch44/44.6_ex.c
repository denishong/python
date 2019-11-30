#include <stdio.h>
#include <string.h>
int main()
{
	int count = 0;
	char s1[1001]; 

	scanf("%[^\n]s", s1);

	char *ptr = strchr(s1, ' ');

	while( ptr != NULL )
	{
		if(ptr != 0)
			count++;
		ptr = strchr(ptr + 1, ' ');
	}

	printf("%d\n", count);
	return 0;
}
