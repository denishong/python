#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN (10)
#define MAXM (100)
int N, M;//직원수, 상하관계개수
int s[MAXM+1];
int e[MAXM+1];
int bonus[MAXN+1];//보너스금액
int sol[MAXN+1];//실제지불
int used[MAXN+1];//지급 완료 표시 
int link[MAXN+1][MAXN+1];//[상급자][하급자] 표시 
bool comp(int a, int b){
	return(a>b);
}
bool isPossible(int n, int p){
	for(int i=1; i<=N; i++){
		if(n == i) continue;//본인임 
		if(sol[i]==0) continue;
		if((link[n][i]) && (sol[i] >= p) ) return false;//
		if((link[i][n]) && (sol[i] <= p) ) return false;//
	}
	return true;
}
bool DFS(int n){
	if(n>N) return true;//보너스 지급 완료 
	for(int i=2; i<=N; i++){
		if(used[i]) continue; //지급 완료 
		if(!isPossible(n, bonus[i]) ) continue;
		used[i]=1;
		sol[n]=bonus[i];
		if(DFS(n+1)) return true;
		used[i]=false;
		sol[n]=0;
	}	
	return false;
}
void Solve(){
	//1.내림차순으로 보너스 정렬 
	sort(&bonus[1],&bonus[1+N],comp);
	//2.사장은 보너스 정해져 있어서 지급 
	sol[1]=bonus[1];
	//3.DFS로 bonus지급 정렬 
	DFS(2);
}
void InputData(){
	cin >> N >> M;
	for (int i=0; i<M; i++){
		cin >> s[i] >> e[i];
		link[s[i]][e[i]]=1;
	}
	for (int i=1; i<=N; i++){
		cin >> bonus[i];
	}
}
void OutputData(){
	for (int i=1; i<=N; i++){
		cout << sol[i] << " ";
	}
	cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력받는 부분
	Solve();// 여기서부터 작성
	OutputData();// 출력하는 부분
	return 0;
}
