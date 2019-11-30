#include <stdio.h>

int main(void)
{
	int i;
	
	char *hoge= "david";

	printf("Output value: %s\n", hoge);

	for(i=0; i<7; i++)
	printf("charter value: %c, %d\n", *(hoge+i),*(hoge+i));
	
	return 0;

}
