#include <stdio.h>

int main()
{


	float num1 = 3e5f;
	double num2 = -1.42;
	long double num3 = 8.92e+2l;
	float num4 = 2.97;
	long double num5 = 7.4e-10l;

	printf("float num1 : %f %e %g\n", num1,num1,num1);
	printf("double num2 : %f\n", num2);
	printf("long double num3 : %Lf %Le %Lg\n", num3,num3,num3);
	printf("float num4 : %f %e %g\n", num4,num4,num4);
	printf("long double num5 : %Lf %Le %Lg\n", num5,num5,num5);
	
	return 0;
}
