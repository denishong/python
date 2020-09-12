#include <stdio.h>

int main(void)
{
	FILE *ii;
	char m1,m2,m3,m4;
	ii = fopen("so4.dat","r");

	fscanf(ii, "%c%c%c%c", &m1,&m2,&m3,&m4);

	printf(" read charters : %c%c%c%c\n", m1,m2,m3,m4);
	fclose(ii);
	return 0;
}
