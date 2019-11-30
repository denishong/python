#include <stdio.h>

int main()
{

	FILE *fp = fopen("hello.txt", "w");

	fputs("hello world!!",fp);

	fclose(fp);

	return 0;
}
