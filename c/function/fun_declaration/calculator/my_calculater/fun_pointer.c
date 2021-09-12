#include <stdio.h>
#include <stdlib.h>

int func_add(void)
{
	printf("Test print a\n");
}


int func_sub(void)
{
	printf("Test print b\n");
}

int func_multiply(void)
{
	printf("Test print c\n");
}

int func_divided(void)
{
	printf("Test print c\n");
}

int(*pFunc[4])() = {func_add, func_sub, func_multiply, func_divided};

int main(int argc, char *argv[])
{

		printf("argument count value is %d!!\n", argc);
	if(argc == 1)
		printf("Please enter arguments!!\n");

	for(int i=0; i<argc; i++)
	printf("argv[%d] : %s\n",i, argv[i]);

	int val1, val2;

	val1 = atoi(argv[1]);
	val2 = atoi(argv[3]);

	printf("value1 %s  %s %s = %d \n", argv[1], argv[2], argv[3], val1 + val2); 

	return 0;
}
