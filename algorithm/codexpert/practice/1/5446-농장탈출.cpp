#include <iostream>
using namespace std;
#define MAXN (20)
int N;
int W[MAXN+10];
int sol;
int isPossible(int a, int b){
	while(a && b){
		if( (a%10 + b%10) >= 10) return 0;
		a/=10;
		b/=10;
	}
	return 1;
}
void DFS(int n, int cnt, int sum){
	if(sol<cnt) sol=cnt;
	if(n>=N) return; //종료조건 
	//n번 소를 태우는 경우 
	if(isPossible(sum,W[n])) DFS(n+1,cnt+1,sum+W[n]);
	//n번소를 태우지 않는 경우 
	DFS(n+1,cnt,sum);
}
int Solve(){
	sol=0;
	DFS(0,0,0);//시작인덱스,마리수,무게 
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
