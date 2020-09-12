#include <stdio.h>

int main(void)
{
	FILE *ii;
	char m1,m2,m3,m4;
	ii = fopen("so1.dat","r");

	m1 = fgetc(ii);
	m2 = fgetc(ii);
	m3 = fgetc(ii);
	m4 = fgetc(ii);

	printf(" read characters : %c%c%c%c. \n", m1,m2,m3,m4);
	fclose(ii);
	return 0;
}
