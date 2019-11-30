#include <stdio.h>

int main()
{
	int *a = 5;
	int size;

	char c;
	char *i;


	int *d;
	int key;
	
	size = 3;

	printf("size pointer address : %p \n", &size);

	a = &size;
	printf("a pointer address :%p a value: %d \n", a, *a);
	printf("sizeof of int : %ld, sizeof of char type : %ld\n", sizeof(int), sizeof(char));

	c = 'a';
	printf(" a value : %c  c address :%p \n", c, &c);

	i = &c;
	printf("i pointer address :%p i value: %c \n", i, *i);


	key = 10;
	
	printf("key address : %p \n", &key);

	d = &key;
	printf("d address :%p d value: %d \n", d, *d);
	return 0;
}
