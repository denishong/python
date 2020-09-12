#include <stdio.h>

int main(void)
{
	FILE *ii;
	char m1,m2,m3,m4;
	ii = fopen("so4.dat","r");

	fscanf(ii, "%c", &m1);
	fscanf(ii, "%c", &m2);
	fscanf(ii, "%c", &m3);
	fscanf(ii, "%c", &m4);

	printf(" read charters : %c%c%c%c\n", m1,m2,m3,m4);
	fclose(ii);
	return 0;
}
