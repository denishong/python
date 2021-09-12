#include <stdio.h>


int main(int argc, char* argv[] )
{

	int a,b,c;
	int max;

	printf("세 정수의 최댓값을 구합니다.\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	max = a;
	if( b > max) max = b;
	if( c > max) max = c;

	printf("Max value is %d\n", max);

	return 0;
}
