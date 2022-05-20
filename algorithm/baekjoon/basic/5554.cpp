/*[baekjoon]5554 심부름 가는 길*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 5)
int N[MAXN];
int total=0;
void InputData(){
    for(int i=0; i<4; i++){
        cin >> N[i];
        total += N[i];
    }
}
void Solve(){
    int minutes, seconds;
    minutes=total/60;
    seconds = total%60;
    cout << minutes <<endl;
    cout << seconds <<endl;
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon]5554 심부름 가는 길*/
