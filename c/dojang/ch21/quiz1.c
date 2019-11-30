#include <stdio.h>

int main()
{

	int num1;
	int num2;

	scanf("%d", &num1);
	scanf("%d", &num2);

	if(num1 && num2)
	printf("참\n");
	else
	printf("거짓\n");


	if(num1 || num2)
	printf("참\n");
	else
	printf("거짓\n");


	if(!num1)
	printf("참\n");
	else
	printf("거짓\n");

	return 0;
}
