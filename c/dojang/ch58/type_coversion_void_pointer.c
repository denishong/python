#include <stdio.h>

int main()
{
	int num1 = 10;
	float num2 = 3.5f;
	char c1 = 'a';
	void *ptr;


	ptr = &num1;
	//printf("%d\n", *ptr);
	printf("%d\n",*(int *)ptr);

	ptr = &num2;
	//printf("%f\n", *ptr);
	printf("%f\n",*(float *)ptr);

	ptr = &c1;
	//printf("%c\n", *ptr);
	printf("%c\n",*(char *)ptr);

	return 0;
}
