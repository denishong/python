/*[baekjoon][10826] 피보나치 수 4*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((long long int) 1e4)
unsigned long long int d[MAXN+10];

unsigned long long int fibonacci(long long int n)
{
    if( n == 0) return 0; 
    else if(n ==1) return 1;
    else if(d[n] != 0) return d[n];
    return d[n]=(fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    long long int n; 
    cin >> n;
	cout << fibonacci(n);

	return 0;
}
/*[baekjoon][10826] 피보나치 수 4*/
