#include <stdio.h>

int main()
{
	char buffer[20];
	FILE *fp;
	
	fp = fopen("data.txt", "r+");

	fgets(buffer, sizeof(buffer), fp);

	printf("%s\n", buffer);

	fclose(fp);

	return 0;

}
