/*[baekjoon] 9095 1,2,3 더하기*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 15)
int T;
int a[MAXN];
void InputData(){
    cin >> T;
}
int Plus(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(a[n]!=0){
        return a[n];
    }
    return a[n] = Plus(n-1) + Plus(n-2) + Plus(n-3);
}
void Solve(){
    int n;
    for(int i=0; i<T; i++){
        cin >> n;
		cout << Plus(n) << endl;
    }
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon] 9095 1,2,3 더하기*/
