#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	int a;

	for(a=1; ; a++)
	{
		putchar('*');
		putchar('\n');
		sleep(1);
	}
	printf("program end");

	return 0;

}
