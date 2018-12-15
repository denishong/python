#include "stdio.h"

int main(void){

	int i=0,size=0;
	int a[7]={1,2,4,5};

	printf("%lu, %lu, %p\n", sizeof(long),sizeof(a)/sizeof(a[0]),(void *) a);
	size=(int) sizeof(a)/sizeof(a[0]);
	for(i=0;i<size;i++)
	printf("%d\n", a[i]);


return 0;

}
