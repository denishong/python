#include <stdio.h>

int main(void)
{
	int i;
	
	char hoge[][6]= {
	"david",
	"cindy",
	};


	for(i=0; i<2; i++){
	printf("string value: %s\n", *(hoge+i));
	printf("string value: %s\n", hoge[i]);
	}
	
	return 0;

}
