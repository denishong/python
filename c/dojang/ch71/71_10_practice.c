#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer;
    int size;
    int count;

	 buffer = malloc(10000);
    FILE *fp = fopen("words.txt", "r");


		fseek(fp, 0, SEEK_END);
		size = ftell(fp);

	while(feof(fp) == 0)
	{
		fseek(fp, 1, SEEK_END);
	 	fread(buffer, 4, 1, fp);
		
    printf("%s", buffer);

	 memset(buffer, 0, 10); 
	 fseek(fp, -7, SEEK_END);
	 fread(buffer, 2, 1, fp);

	 printf("%s", buffer);

    fclose(fp);

    free(buffer);

    return 0;
}
