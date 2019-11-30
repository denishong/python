#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *getName()
{
	char *s1 = malloc(20);

	strcpy(s1, "Neptune");

	return s1;
}

int main()
{
    char *name;

    name = getName();
 
    printf("%s\n", name);

    free(name);

    return 0;
}
