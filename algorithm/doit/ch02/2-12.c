#include <stdio.h>

int main(int argc, char* argv[])
{
	int year;
	scanf("%d", &year);

	printf( "%d\n", year % 4 ==0);

	return 0;
}
