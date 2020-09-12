#include <stdio.h>

int main()
{
	FILE *pp;

	pp = fopen("./test.txt","w+");
	fputc('A', pp);
	fputc('B', pp);
	fclose(pp);
	return 0;
}
