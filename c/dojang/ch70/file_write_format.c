#include <stdio.h>

int main()
{
	FILE *fp = fopen("hello.txt", "w");

	fprintf(fp, "%s %d %f\n", "Hello world!", 100, 121.3);
	fprintf(fp, "%s %d %f\n", "test111!", 100, 121.3);
	fprintf(fp, "%s %d %f", "ilkjdflaj", 100, 121.3);
	fprintf(fp, "%s %d %f", "sldkfjalsdkjf", 100, 121.3);

	fclose(fp);

	return 0;
}
