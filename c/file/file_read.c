#include <stdio.h>

int main()
{
	FILE *fp;
	char *string;
	fp = fopen("test.txt", "wr");
	fscanf(fp, "%s", string);
	printf("%s\n", string);
	fclose(fp);

	return 0;
}
