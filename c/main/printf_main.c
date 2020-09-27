#include <stdio.h>


int main(int argc, char* argv[])
{

	char str[30];
	FILE* fp;
	fp = fopen("a.txt", "r");

	fgets(str, sizeof(str), fp);

	//printf("%s\n", argv[1]);
	printf("%s\n", str);

	fclose(fp);
	return 0;
}
