#include <stdio.h>
#include <string.h>

int main()
{

	int count;
	char buffer[5] = { 0, };
	
	FILE *src = fopen("hello.txt", "r");
	FILE *dest = fopen("hello2.txt", "w");

	while( feof(src) == 0)
	{
		count = fread(buffer, sizeof(char), 4, src);
		printf("%s", buffer);
		fwrite(buffer, sizeof(char), count, dest);
		memset(buffer, 0, 5);
	}

	fclose(src);
	fclose(dest);

	return 0;
}

