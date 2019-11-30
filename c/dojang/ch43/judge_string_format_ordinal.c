#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int number;
    char name[31], result[40];


	scanf("%d", &number);
	scanf("%s", name);

	if( number ==1)
		sprintf(result, "%d%s", number, "st");
	else if( number ==2)
		sprintf(result, "%d%s", number, "nd");
	else if( number ==3)
		sprintf(result, "%d%s", number, "rd");
	else
		sprintf(result, "%d%s", number, "th");

	sprintf(result,"%s %s",result, name);

    printf("%s\n", result);

    return 0;
}
