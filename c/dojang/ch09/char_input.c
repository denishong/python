#include <stdio.h>

int main(int argc, char* argv[])
{
	int i;
	if(argc == 1)
		printf("error input argument!!\n");

	for(i=1; i<argc; i++)
		printf(" charter test : %c, %d\n", *argv[i], *argv[i]);

	return 0;
}
