#include <stdio.h>
#include <string.h>

int main()
{

	char *s1 = "Test case,Hello world! ";
	FILE *fp = fopen("hello.txt", "w");

	fwrite(s1, strlen(s1), 2,fp);

	fclose(fp);

	return 0;
}
