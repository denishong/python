#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ret=system("./main");
	if(ret == 0)
	printf("main function\n");
	
}
