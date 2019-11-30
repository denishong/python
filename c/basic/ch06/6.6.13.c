#include <stdio.h>

int main(){

	char M;
	M='a';
	
	printf("<<영문소문자>>\n");

	while(M<='z')
		putchar(M++);	
	
	printf("program end\n");

	return 0;

}	
