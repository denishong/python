#define _CR_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char s1[10];

	printf(" Input charaters : ");

	//scanf("%s", s1);
	scanf("%[^\n]s", s1);
	printf("%s\n",s1);

	return 0;
}

