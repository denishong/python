#include <stdio.h>

int main(void)
{
	FILE *ii;
	char name[11];
	int age;
 
	ii = fopen("so8.dat","r");

	fscanf(ii, "%15s%3d", name,&age); 
	printf("%20s%10d\n", name, age); 

	fscanf(ii, "%10s%3d", name,&age); 
	printf("%20s%10d\n", name, age); 
	
	fscanf(ii, "%10s%3d", name,&age); 
	printf("%20s%10d\n", name, age); 

	fclose(ii);
	return 0;
}
