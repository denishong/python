#include <stdio.h>

int main()
{
	int numArr[3][4] = {
		{11,22,33,44},
		{55,66,77,88},
		{99,110,121,132}
	};

	printf("%ld\n",sizeof(numArr));
	printf("%ld\n", sizeof(numArr[0]));
	printf("%ld\n", sizeof(numArr[0][0]));

	return 0;
}
