#include <stdio.h>

void myvalue(int a, int b)
{
	printf("value a: %d, value b: %d\n", a,b);
}


int main()
{
	int a,b;
	a = 3;
	b = 5;

	myvalue(a,b);

	return 0;

}
