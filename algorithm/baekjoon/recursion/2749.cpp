/*[baekjoon][2749] 피보나치 수 3*/
#include <iostream>
using namespace std;
#define MAXN ((long long int) 1e4)
long long int d[MAXN+10];

long long int fibonacci(long long int n)
{
    if( n == 0) return 0; 
    else if(n ==1) return 1;
    else if(d[n] != 0) return d[n]%1000000;
    return d[n]=(fibonacci(n-1) + fibonacci(n-2))%1000000;
}

int main(){
    long long int n; 
    cin >> n;
	cout << fibonacci(n);
	return 0;
}
/*[baekjoon][2749] 피보나치 수 3*/
