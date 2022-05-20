#include <iostream>
using namespace std;
 
int N, K;
int coin[101];
int dp[10001];
 
void InputData(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> coin[i];
}
void solve(){
    dp[0] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = coin[i]; j <= K; j++){
            dp[j] = dp[j] + dp[j-coin[i]];
			cout<<"i,j,dp[j], dp[j-coin[i]];
        }
    }
    cout << dp[K] << '\n';
}
int main(){
    InputData();
    solve();
return 0;
}
