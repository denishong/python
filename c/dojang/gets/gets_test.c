#include <stdio.h>

int main()
{

	char input[12];
	
	fgets(input,12,stdin);

	printf("%s\n", input);

	return 0;
}
