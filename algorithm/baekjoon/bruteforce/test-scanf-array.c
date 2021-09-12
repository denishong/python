#include <stdio.h>

int main(void)
{

	int i,size=0;
	char test[5];

	size = sizeof(test)/sizeof(char);

	for(i =0; i<size; i++)
	scanf("%c", &test[i]);

	for(i=0; i<size; i++)
	printf("test[%d] : %c ", i, test[i]);

	return 0;
}
