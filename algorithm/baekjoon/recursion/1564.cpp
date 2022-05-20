/*baekjoon 1564 팩토리얼5*/
#include <bits/stdc++.h>
using namespace std;
int N;
unsigned long factorial(int n)
{
	if(n > 0){
        cout << "n >0 :" << n << endl;
		return n+factorial(n-1);
    }else{
        cout << "else :" << n << endl;
		return 0;
    }
}
void InputData(){
    cin >> N;
}
int main()
{
    InputData();
	cout <<  factorial(N) ;
    return 0;
}
/*baekjoon 1564 팩토리얼5*/
