#include <stdio.h>

int main()
{
	int M;

	printf("%20s\n", "* 영문   대문자*");
		for(M=0; M<=127; M++)
			printf("%c",M);

	printf("\n 출력 끝");
}
