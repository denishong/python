/*baekjoon 2667 DFS,BFS 단지번호 붙이기*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 25 

int N,house,cnt;// 정점수 , 간선수 , 시작점 
int sol[MAXN*MAXN];
char map[MAXN+10][MAXN+10];
int sizApt[323] = {0, };
int dy[]={-1, 1, 0, 0};
int dx[]={0, 0, 1, -1};

void DFS(int y, int x){
	if(map[y][x] != '1') return;
	map[y][x] = '0';
	house++;

	for(int i=0; i<4; i++){
		DFS(y+dy[i], x+dx[i]);
		cout << "dy, dx" <<  y+dy[i] << ' ' << x+dx[i] << endl;
	}
}
void Solve(){
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(map[i][j] == '1' ){
				house=0;
				cout << i << ' ' << j << endl;
				DFS(i,j);
				sol[cnt++]=house;
			}
		}
	}
}
bool comp(int a, int b){ return a < b;}
void OutputData(){
	sort(sol, sol+cnt, comp);
	cout <<  cnt << endl;
	for(int i=0; i<cnt; i++){
		cout << sol[i] << endl;
	}
}

void InputData(){
	cin >> N;
	for( int i=1; i<=N; i++){
		cin >> &map[i][1];
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	InputData();
	Solve();
	OutputData();

	return 0;
}
/*baekjoon 2667 DFS,BFS 단지번호 붙이기*/
