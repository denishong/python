#include <stdio.h>

int main(void)
{
	FILE *ii;
	char m1[21],m2[21],m3[21];
	ii = fopen("so2.dat","r");

	fgets(m1,5,ii);
	fgets(m2,5,ii);
	fgets(m3,5,ii);

	printf(" m1: %s. \n", m1);
	printf(" m2: %s. \n", m2);
	printf(" m3: %s. \n", m3);
	fclose(ii);
	return 0;
}
