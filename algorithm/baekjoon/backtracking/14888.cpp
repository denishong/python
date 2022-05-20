/*[baekjoon]14888번 연산자 끼워넣기*/
#include <bits/stdc++.h>
using namespace std;
#define MAX ((int) 1e9+1)
int N;
int A[12];
int Operator[4];
int maxResult = -MAX, minResult = MAX;
void DFS(int plus, int minus, int multiply, int divide, int cnt, int sum){
    if( cnt == N){
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);
    }
    if(plus > 0)
        DFS(plus-1, minus, multiply, divide, cnt+1, sum+A[cnt]);
    if(minus > 0)
        DFS(plus, minus-1, multiply, divide, cnt+1, sum-A[cnt]);
    if(multiply > 0)
        DFS(plus, minus, multiply-1, divide, cnt+1, sum*A[cnt]);
    if(divide > 0)
        DFS(plus, minus, multiply, divide-1, cnt+1, sum/A[cnt]);
}
void Solve(){
    DFS(Operator[0], Operator[1], Operator[2], Operator[3],1,A[0]);
    cout << maxResult << endl;
    cout << minResult << endl;
}
void InputData(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<4; i++){
        cin >> Operator[i];
    }
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon]14888번 연산자 끼워넣기*/
