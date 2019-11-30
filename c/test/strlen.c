#include <stdio.h>


int strlen(const char *s)
{
	const char *sc = s;
	
	while (*sc != '\0')
		sc++;
	return sc - s;
}

int main(int ac, char *av[])
{

	int i,strlength;
	if(ac == 1)
		printf("error input argument!!\n");

	strlength = strlen( av[1]);

	printf("string length : %d\n", strlength);

	return 0;
}
