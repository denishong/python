#include <stdio.h>

int main(void)
{
	int i;
	char arr[]={'G','o','o','d','m','o','r','n','i','n','g'};
	int arrLen=sizeof(arr)/sizeof(char);

	for(i=0; i<arrLen; i++)
		printf("%c ", arr[i]);
	printf("\n");

	return 0;
}
