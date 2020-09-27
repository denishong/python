#include <stdio.h>

int main()
{

	FILE *fp;

	fp = fopen("test.txt", "wr");

	fprintf(fp, "test");


	fclose(fp);

	return 0;
}
