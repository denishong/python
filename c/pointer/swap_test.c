#include <stdio.h>


void swap(int* a, int* b)
{

	int* temp;

	printf("temp=%x *a=%x\n", *temp, *a);
	*temp=*a;
	printf("temp=%x *a=%x\n", *temp, *a);

	*a=*b;
	*b=*temp;

}

int main(){

	int a,b;

	a=3;
	b=5;

	printf("%d %d\n", a, b);
	printf("%p %p\n", &a, &b);
	
	swap(&a,&b);

	printf("%d %d\n", a,b);

	return 0;
}
