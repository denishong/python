#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 25
int N,house,cnt;
char map[MAXN+10][MAXN+10];
int sol[MAXN*MAXN];
int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};

void InputData(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> &map[i][1];
	}
}
bool comp(int a, int b) {return a < b;}
void OutputData(){
	sort(sol, sol+cnt, comp);
	cout << cnt << endl;
	for(int i=0; i<cnt; i++){
		cout << sol[i] << endl;
	}
}
void DFS(int y, int x){
	if(map[y][x] !='1') return;
	map[y][x] = '0';
	house++;

	for(int i=0; i<4; i++){
		DFS(y+dy[i], x+dx[i]);	
	}

}
void Solve(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j] =='1'){ 
			house=0;
			DFS(i,j);
			sol[cnt++]=house;
			}
		}
	}
}
int main(){
	InputData();
	Solve();
	OutputData();
	return 0;
}
