#include <stdio.h>

int main()
{
	int a,b;
	float c;

	printf("int %d byte, float %d bytes\n",sizeof(a), sizeof(c));
	printf("int %d byte, float %d bytes\n",sizeof(int), sizeof(float));
	printf("int %d byte, float %d bytes, double %d bytes\n",sizeof(int), sizeof(float), sizeof(double));

	return 0;
}
