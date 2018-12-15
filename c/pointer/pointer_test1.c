#include <stdio.h>


int addone(int* a){

	*a=*a+1;
	return *a;
}

int main(){

	int a=3;
	int *p; 

	printf("a=%d\n",a);
	printf("*p=%d\n",*p);
	printf("p=%p\n",p);
	p = &a;
	printf("&a=%p\n",&a);
	printf("p=%p\n",p);
	printf("&p=%p\n",&p);

	a=5;
	printf("a=%d\n",a);

	addone(&a);
	printf("a=%d\n",a);
	
	return 0;

}
