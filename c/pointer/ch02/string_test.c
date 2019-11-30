#include <stdio.h>

int main(void)
{
	char **hoge;
	int i;

	**(hoge) = "david";
 	**(hoge+1) = "denis hong";
	**(hoge+2) = "heidi hong";

	printf("Output value.\n");
	for(i=0; i < 2; i++){

	printf("hoge+i : %s\n", *(hoge+i));

	}
	return 0;

}
