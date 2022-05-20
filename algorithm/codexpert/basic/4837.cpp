#include <bits/stdc++.h>
using namespace std;
int M;
void InputData(){ 
	cin >> M; 
}
void OutputData(int ans){
	if (ans == 0) cout << "NO" << endl;
	else cout << "YES" << endl;
}
int reverse(int num){
	int ret=0;
	while(num>0){
		ret=ret*10 + num%10;
		num /= 10;
	}
	return ret;
}
int Solve(int m){
	int sum=m+reverse(m);
	if(sum==reverse(sum)) return 1;
	return 0;
}
int main() {
	int N, i, ans;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> M;
		ans=Solve(M);
		OutputData(ans);
	}
	return 0;
}
