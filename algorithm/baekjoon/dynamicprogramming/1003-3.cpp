/*[baekjoon][1003]피보나치 함수*/
#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int cnt0, cnt1;
void InputData(void){
  cin >> T;
}
void Solve(void){
	int dp[41]={0,1,1};
	for(int i=3; i<41; i++) dp[i]=dp[i-1]+dp[i-2];
	for(int i=0; i<T; i++){
		cin>>N;
		if(N==0) cout<<1<<' '<<0<<endl;
		else if(N==1) cout<<0<<' '<<1<<endl;
		else cout<<dp[N-1]<<' '<<dp[N]<<endl;
	}
}
int main(void){
  InputData();
  Solve();
  return 0;
}
/*[baekjoon][1003]피보나치 함수*/
