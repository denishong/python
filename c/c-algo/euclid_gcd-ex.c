#include <stdio.h>

int gcd(int a, int b){
	if (b == 0) return a;
	gcd(b,a%b);
}

int main(void)
{

	int m, n, r;

	printf("Input two numbers\n");
	scanf("%d %d", &m, &n);

	if(m < n)
		r = m; m = n; n = r;
	
	printf("GCD : %d \n", gcd(m,n));
	return 0;
}
