#include <stdio.h>

//#define __init      __section(.init.text) __cold notrace
#define __init      __section(.init.text) 
#define __section(S) __attribute__ ((__section__(#S)))
#define __cold      __attribute__((__cold__))
#define notrace __attribute__((no_instrument_function))

static void __init start_kernel()
{
	printf("__init macro??\n");
}

int main()
{
 	start_kernel();

	return 0;
}
