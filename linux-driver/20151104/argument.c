#include <stdio.h>
// ./a.out    1    2   3
// argv[0] argv[1] ...
// argc=4

int main(int argc, char **argv)
{
	int local=10;;
	printf("&local=%p\n", &local );
	printf("&argc=%p\n", &argc );
	printf("&argv=%p\n", &argv );
	printf("argv=%p\n", argv );
	printf("argv[0]=%p\n", argv[0] );
	printf("argv[1]=%p\n", argv[1] );
	printf("argv[2]=%p\n", argv[2] );
	return 0;
}
