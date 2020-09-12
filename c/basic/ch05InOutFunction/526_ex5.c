#include <stdio.h>

int main(void)
{
	FILE *ii;
	int num1,num2,num3;	
	ii = fopen("so7.dat","r");

	fscanf(ii, "%d%d%d", &num1, &num2,&num3); 

	printf(" num1 : %d num2 : %d num3 : %d\n",num1,num2,num3); 
	fclose(ii);
	return 0;
}
