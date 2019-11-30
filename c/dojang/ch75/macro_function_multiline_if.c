#include <stdio.h>

#define PRINT_NUM(x) printf("%d\n", x)
#define PRINT_NUM3(x) printf("%d\n", x);\
								printf("%d\n", x + 1); \
								printf("%d\n", x + 2);

int main()
{
	int num1 = 1;
	if( num1 == 2)
	{
		PRINT_NUM3(10);
	}

	return 0;
}
	
