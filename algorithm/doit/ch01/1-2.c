#include <stdio.h>

int max3(int a, int b, int c)
{
	int max =a;
	if( b > max) max = b;
	if( c > max) max = c;

	return max;
}

int main(int argc, char* argv[] )
{

	printf("max3(%d, %d, %d) = %d\n", 3, 2, 1,  max3(3, 2, 1));
	printf("max3(%d, %d, %d) = %d\n", 3, 2, 2,  max3(3, 2, 2));
	printf("max3(%d, %d, %d) = %d\n", 3, 1, 2,  max3(3, 1, 2));

	return 0;
}
