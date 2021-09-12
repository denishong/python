#include <bits/stdc++.h>
using namespace std;

int factorial(int a)
{
	if(a > 2){
		cout << "factorial: %d " << a << '\n';		
		return a*factorial(a-1);
	}
}


int main()
{
    int i,repeat;
	int fact=1; 
    cin >> repeat;
	
	printf("%d\n", factorial(repeat));

    return 0;
}
