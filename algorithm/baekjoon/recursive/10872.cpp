/*baekjoon 10872 팩토리얼*/
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
	if(n > 0)
		return n*factorial(n-1);
	else
		return 1;
}
int main()
{
    int x;
    cin >> x;

	cout <<  factorial(x) ;
    return 0;
}
/*baekjoon 10872 팩토리얼*/
