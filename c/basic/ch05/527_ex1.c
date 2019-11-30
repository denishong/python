#include <stdio.h>

int main(void)
{
	FILE *ii;
	char m1,m2,m3;
	ii = fopen("so4.dat","r");

	fgets(m1,5,ii);
	fgets(m2,5,ii);
	fgets(m3,5,ii);

	printf(" m1: %s", m1);
	printf(" m2: %s", m2);
	printf(" m3: %s", m3);
	fclose(ii);
	return 0;
}
