#if 1
#include <stdio.h>

int my_init(void)
{
	printf("my_init()\n");
}

int init_module(void) __attribute__((alias("my_init")));

//-------------------------------------
int main()
{
	init_module();
	return 0;
}
#endif
#if 0
#include <stdio.h>

void bar(void)
{
	printf("bar()\n");
}

void foo(void) __attribute__((alias("bar")));

//-------------------------------------
int main()
{
	foo();
	return 0;
}
#endif
