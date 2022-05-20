/*baekjoon 7576 토마토 BFS*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 1e3+10 )

int N, M ;// 정점수 , 간선수 , 시작점 
int mmap[MAXN][MAXN];
bool mapCheck[MAXN][MAXN];
int path[MAXN][MAXN];
int cnt;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
queue<pair<int,int>> q;

bool isInside(int a, int b){
	return (a>=0 && a<N) && (b>=0 && b<M);
}

void Solve(){
	int x,y,nx,ny;
	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if(isInside(ny, nx) && mmap[ny][nx] == 0 && mapCheck[ny][nx] == 0 ){
				mapCheck[ny][nx] = 1;
				q.push( pair<int, int>(ny, nx) );
				path[ny][nx] = path[y][x] + 1;
			}
		}
	}
}
void OutputData(){
	for( int i=0; i < N; i++){
		for( int j=0; j < M; j++){
			cout << path[i][j] << ' ';
		}
		cout << endl;
	}
}

void InputData(){
	cin >> M >> N;
	for( int i=0; i < N; i++){
		for( int j=0; j < M; j++){
			cin >> mmap[i][j];
			if(mmap[i][j]==1){
				q.push( pair<int,int>(i, j) );
				mapCheck[i][j]=1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	InputData();
	Solve();

	for( int i=0; i < N; i++){
		for( int j=0; j < M; j++){
			if( mmap[i][j] == 0 && path[i][j] == 0 ){
				cout << -1 << endl;	
				return 0;
			}
		}
	}

	int ans = -1;
	for( int i=0; i < N; i++){
		for( int j=0; j < M; j++){
			if( path[i][j] > ans ){
				ans = path[i][j];	
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*baekjoon 7576 토마토 BFS*/
