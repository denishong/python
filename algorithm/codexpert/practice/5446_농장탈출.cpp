#include <iostream>
using namespace std;
#define MAXN (20)
int N;
int W[MAXN+10];
int sol;
bool isPossible(int a, int b){
	while(a && b){
		if( (a%10 + b%10) >=10) return false;//자리올림 발생,태우기 불가능 
		a/=10;
		b/=10;
	}
	return true;
}
void DFSmulti(int s, int cnt, int sum){
	if(sol>=cnt+N-s) return; //가지치기,이전답>=현재까지 태운소+남은모든소 
	if(sol<cnt) sol=cnt;

	for(int i=s; i<N; i++){
		if(!isPossible(sum,W[i]) ) continue;//i번소는 자리올림 발생,skip
		DFSmulti(i+1, cnt+1, sum+W[i]);
	}
}
int Solve(){
	sol=0;
	DFSmulti(0,0,0);//시작인덱스,태운마리수,무게합 
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
