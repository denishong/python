#include <iostream>
using namespace std;
#define MAXN (20)
int N;
int W[MAXN+10];
int sol;
bool isPossible(int a, int b){
	while(a && b){
		if(a%10 + b%10>=10) return false;
		a/=10;
		b/=10;
	}
	return true;
}
void DFS(int n, int cnt, int sum){
	if(sol<cnt) sol=cnt;//답갱신 
	for(int i=n; i<N; i++){
		if(!isPossible(sum, W[i])) continue;
		DFS(i+1, cnt+1, sum+W[i]);
	}
}
void DFSBinary(int n,int cnt, int sum){
	if(sol<cnt) sol=cnt;
	if(n>=N) return;
	if(isPossible(sum,W[n])) DFSBinary(n+1, cnt+1, sum+W[n]);
	DFSBinary(n+1, cnt, sum+W[n]);
}
int Solve(){
	sol=0;
	DFSBinary(0,0,0); //인덱스,태운마리수,무게 누적
	return sol;
}
void InputData(){
	cin >> N;
	for (int i=0 ; i<N ; i++){
		cin >> W[i];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	InputData();// 입력받는 부분

	ans=Solve();// 여기서부터 작성

	cout << ans << "\n";//출력하는 부분
	return 0;
}
