#include <stdio.h>

int GCD(int a, int b);

int GCD(int a, int b)
{
	printf("%d %d \n", a, b);

	if(b == 0)
		return a;

	GCD(b, a%b);
}

int main(void)
{

	int m, n, r;

	printf("Input two numbers\n");
	scanf("%d %d", &m, &n);

	if(m < n)
		r = m; m = n; n = r;
	
	r = GCD(m, n);

	printf("GCD : %d \n", r);

	return 0;
}
