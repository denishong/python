#include <stdio.h>

int main(void)
{
	char str[]="Good morning!";

	printf("array size : %d ",(int) sizeof(str));
	printf("print null charater: %c ", str[13]);
	printf("print null integer : %d ", str[13]);
	printf("\nprint string : %s \n", str);

	str[12]='?';	
	printf("print string : %s \n", str);

	return 0;
}
