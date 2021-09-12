#include <stdio.h>
#include "extern.h"

extern void  print_num(void);
void print_num(void){
	printf("this is extern_print.cpp" );
	printf("num1:%d\n", num1);
}
