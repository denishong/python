#include <stdio.h>

void s(int n)
{
	if(n == 3) return;
	else{
	printf("%d", n);
	s(n+1);
	}
	printf("%d", n);
}

int main(void)
{
	puts("<< main function >>");
	s(1);
	puts("\n return to  main function ");
	return 0;
}
