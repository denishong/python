#include <stdio.h>

int main()
{

	char s1[10];
	int num1;

	FILE *fp = fopen("hello.txt", "r");

	for(int i=0; i <= 3; i++)
	{
		fscanf(fp, "%s  %d", s1, &num1);
		printf("%s %d\n", s1, num1);
	}

	fclose(fp);

	return 0;
}
