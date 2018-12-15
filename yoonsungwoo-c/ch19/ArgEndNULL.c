#include <stdio.h>

int main(int argc, char *argv[])
{

	int i=0;
	printf("delivered character's number: %d \n", argc);

	while(argv[i] != NULL)
	{
		printf("%d th charater: %s \n",i, argv[i]);
		i++;
}

	return 0;
}
