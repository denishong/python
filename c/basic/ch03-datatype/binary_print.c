#include <stdio.h>
#include <stdlib.h>

int main()
{

	char buf[33]; // or 65 for 64-bits
	int num = 13;
	itoa(num, buf, 2);
	printf("%s\n", buf);			
	return 0;
}
