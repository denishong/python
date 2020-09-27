#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc < 2)
		printf(" error argc is too small!! \n");

	printf("string size : %ld\n", sizeof( argv[1] ));
	printf("string is : %s\n",  argv[1] );
	printf("string is : %p\n",  argv[1] );


	while(&argv[1]++!='\n')
		printf("ssss %c\n", &argv[1]);

	return 0;
}
