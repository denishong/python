#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[] )
{

	int a,b,c;
	int max;

	printf("argc : %d\n", argc);

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	printf("세 정수의 최댓값을 구합니다.\n");
	
	max = a;
	if( b > max) max = b;
	if( c > max) max = c;

	printf("Max value is %d\n", max);

	return 0;
}
