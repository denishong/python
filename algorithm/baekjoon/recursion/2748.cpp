/*[baekjoon][2748] 피보나치 수 2*/
#include <bits/stdc++.h>
using namespace std;
long long int d[100];

long long int fibonacci(int n)
{
    if( n == 0) return 0; 
    else if(n ==1) return 1;
    else if(d[n] != 0) return d[n];
    return d[n]=(fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    int n; 
    cin >> n;
	cout << fibonacci(n);

	return 0;
}
/*[baekjoon][2748] 피보나치 수 2*/
