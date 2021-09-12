#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
int N;
int paper[MAXN +10][MAXN+10];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
void FillPaper(int sh, int sw, int eh, int ew){
	for(int i=sh; i<eh; i++){
		for(int j=sw; j<ew; j++){
			paper[i][j] = 1;
		}
	}
}
void InputData(){
	int sw, sh;
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> sw >> sh;
		FillPaper(sh, sw, sh+10, sw+10);
	}
}
int Check(int sh, int sw){
	int cnt=0;
	int nw,nh;
	for(int i=0; i<4; i++){
		nw= sw+dx[i];
		nh= sh+dy[i];
		if(nw<0 || nw>=MAXN || nh <0 ||	nh>=MAXN || !paper[nh][nw]){
			cnt++;
		}
	}
	return cnt;
}
void Solve(){
	int sum=0;
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			if(paper[i][j] ==0) continue;
			sum += Check(i,j);
		}
	}
	cout << sum << endl;
}
int main(){
	InputData();
	Solve();
	return 0;
}
