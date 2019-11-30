#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float num1;

    scanf("%f", &num1);

	num1 = (int) num1;
	printf("%d\n",(int) num1);
    return 0;
}
