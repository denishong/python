#include <stdio.h>

int main(void)
{
	int i;
	
	char **hoge={
	"david",
	"cindy",
	};

	for(i=0; i<2; i++)
	printf("charter value: %s\n", *(hoge+i));
	
	return 0;

}
