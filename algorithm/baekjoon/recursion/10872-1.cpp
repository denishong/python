/*baekjoon 10872 팩토리얼*/
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
	int total=1;
	for(int i=n; i>0; i--)
		total *= n;
	return total;
}
int main()
{
    int x;
    cin >> x;

	cout <<  factorial(x) ;
    return 0;
}
/*baekjoon 10872 팩토리얼*/
