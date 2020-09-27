#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc < 2)
		printf(" error argc is too small!! \n");

	//printf("atoi test %d\n", atoi((char*) argv[1]));
	printf("atoi test %d\n", (char*) argv[1]);
	printf("sum = %d\n",  atoi(argv[1]) + atoi(argv[2]));
	return 0;
}
