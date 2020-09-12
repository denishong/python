#include <stdio.h>
int main()
{
	char *irum;

	printf("Name?");
	gets(irum);

	printf("Name is %s", irum);
	return 0;
}
