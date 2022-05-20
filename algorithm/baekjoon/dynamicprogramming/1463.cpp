/*[baekjoon] 1463 1로 만들기*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 15)
int N;
int check_cnt=0;
void InputData(){
    cin >> N;
}
int Plus(int n){
    if(n%3==0){
        check_cnt++;
        return Plus(n/3);
    }else if(n%2==0){
        check_cnt++;
        return Plus(n/2);
    }else if(n%3!=0 && n%2!=2){
        check_cnt++;
        return Plus(n-1);
    }
    if(n==1){
       cout << check_cnt << endl;
       return 0; 
    }
    return 0;
}
void Solve(){
    Plus(N);
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon] 1463 1로 만들기*/
