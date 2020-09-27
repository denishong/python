#include <stdio.h>

int main(void)
{

	char string = "Hong";
	char* strarr[3]={"Simple","String","Array"};
	printf("%s \n", strarr[0] );
	printf("%s \n", strarr[1] );
	printf("%s \n", strarr[2] );
	printf("test string : %s \n", &string );

	for(int i =0; i < 6; i++)
		printf("%c", (char) *(strarr[0] + i) );

	printf("%c \n", (char) *strarr[0] );
	printf("%c \n", (char) *(strarr[0]+1) );
	printf("%c \n", (char) *(strarr[0]+2) );
	printf("%c \n", (char) *(strarr[0]+3) );
	printf("%c \n", (char) *(strarr[0]+4) );
	printf("%c \n", (char) *(strarr[0]+5) );
	printf("%c \n", (char) *(strarr[0]+6) );


	return 0;
} 
