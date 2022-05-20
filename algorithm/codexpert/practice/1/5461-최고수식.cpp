#include <iostream>
using namespace std;
#define MAXM (7)
int N;//임의의수
int WV[2][MAXM+1];
int A;//하나당 추가 가치

int sol;//가장 가치가 높은 수식의 수식 가치
int solcnt[MAXM+1];//사용횟수
int cnt[MAXM+1];//사용횟수
int twopower[]={1,2,4,8,16,32,64};
void DFS(int n, int val, int p){
	if(val==0){
		if(sol<p){
			sol=p;
			for(int i=0; i<MAXM; i++){
				solcnt[i]=cnt[i];
			}
		}
	return;
	}
	if(n>MAXM) return;//
	if(val<twopower[n]) return;
	for(int i=val/twopower[i]; i>=0; i--){
		cnt[n]=i;
		DFS(n+1, val-twopower[n]*i, p+(WV[i>4][i]+A)*i);
		cnt[n]=0;
	}
}
void Solve(){
	sol=0;
	DFS(0,N,0); //2의 제곱수, N(만들수), 가치 
}
void InputData(){
	cin >> N;
	for (int i=0; i<2; i++){
		for (int j=0; j<MAXM; j++){
			cin >> WV[i][j];
		}
	}
	cin >> A;
}
void OutputData(){
	cout << sol << "\n";
	for (int i=0; i<MAXM; i++){
		cout << solcnt[i] << " ";
	}
	cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	Solve();//여기서부터 작성
	OutputData();//출력
	return 0;
}
