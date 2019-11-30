#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *buffer;
	int size;
	int count;

	FILE *fp = fopen("words.txt", "r");

	fseek(fp, 0, SEEK_END);

	size = ftell(fp);

	buffer = malloc(size);
	memset(buffer, 0, size);

	fseek(fp, 0, SEEK_SET);
	count = fread(buffer, size, 1, fp);

	for(int i=size-1; i>=0; i--)
		fwrite(&buffer[i],sizeof(char),1,stdout);

	fclose(fp);
	free(buffer);

	return 0;
}
