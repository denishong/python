/*baekjoon 10872 팩토리얼*/
#include <iostream>
using namespace std;
int N;
long long int d[100];
long long int factorial(int n)
{
    //if(d[n] != 0) return d[n];
    if(n > 1){
        cout << " n: " << n << " " <<  __LINE__ << endl;
        return n*factorial(n-1);
    }else{
        cout << " n: " << n << " " <<  __LINE__ << endl;
        return 1;
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
/*baekjoon 10872 팩토리얼*/
