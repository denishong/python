#include <stdio.h>

int main()
{

	FILE *fp;
	char *name;
	int n = 0;

	fp = fopen("test.txt", "w+");

	while(n <= 3)
	{
		printf("name?\n");
		gets(name);

		fprintf(fp, "%s\n", name);
		n++;
	}	


	fclose(fp);

	return 0;
}
