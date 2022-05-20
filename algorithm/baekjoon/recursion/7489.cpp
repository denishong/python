/*baekjoon 7489 팩토리얼*/
#include <bits/stdc++.h>
using namespace std;
int T,N;
long long int d[100];
long long int factorial(int n)
{
    if(d[n] != 0) return d[n];
    if(n > 1){
        return d[n]=n*factorial(n-1);
    }else{
        return 1;
    }
}
void InputData(){
    cin >> T >> N;
}
int main()
{
    int out, tmp;
    InputData();
    for(int i=0; i<T; i++){
        out  =  factorial(N) ;
        if( out%10 != 0){
            cout << out%10 << endl;
        }else if(out%10 == 0){
            while( tmp%10 == 0){
                tmp = out/10;
            }
            cout << tmp%10;
        }
    }
    return 0;
}
/*baekjoon 7489 팩토리얼*/
