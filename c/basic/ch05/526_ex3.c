#include <stdio.h>

int main(void)
{
	FILE *ii;
	char irum1[11],irum2[11],irum3[11]; 
	ii = fopen("so5.dat","r");

	fscanf(ii, "%s%s%s", irum1, irum2,irum3); 

	printf(" irum1 : %s\n",irum1); 
	printf(" irum2 : %s\n",irum2); 
	printf(" irum3 : %s\n",irum3); 
	fclose(ii);
	return 0;
}
