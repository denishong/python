#include <iostream>
#define MAXN 100010
using namespace std;
int N;//입력 갯수 
int A[MAXN];//입력 데이타 저장할 배열 
int dp[MAXN];//다이나믹 프로그래밍 저장용 배열 
 
void Solve(){
    dp[1] = A[1];
    int sol = dp[1];
    for (int i = 2; i <= N; i++){
        dp[i] = max(A[i], dp[i-1] + A[i]);
        if(sol<dp[i])  sol= dp[i];
    }
    cout << sol << endl;
}
 
void InputData(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
}
int main(void){
	InputData();
    Solve();
    return 0;
}
