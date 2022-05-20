#include <iostream>
#include <queue>
#include<tuple>
using namespace std;
#define MAXN 1001

int N, M;//세로,가로
int map[MAXN][MAXN];
int visited[MAXN][MAXN][2];
int dy[4] = { -1,1,0,0 };//상하좌우
int dx[4] = { 0,0,-1,1 };

int BFS() {
  //1.queue 초기화
  int x,y,z;
  queue<tuple<int,int,int>>q;
  //2.큐에 초기값 입력
	q.push({1, 1, 0});//cnt 1부터 시작
	visited[1][1][0] = 1;
  //3.반복문
	while (!q.empty()) {
    tie(x,y,z) = q.front();q.pop();

		if (x == N && y == M)return visited[N][M][1];
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > M)continue;
			if (map[nx][ny] == 0 && visited[nx][ny][z]==0) {
				visited[nx][ny][z] = visited[x][y][z] +1;
				q.push(make_tuple(nx, ny, z));
			}
			if (map[nx][ny] == 1 && z == 0 && visited[nx][ny][z+1]==0) {
				visited[nx][ny][1] = visited[x][y][z] +1;
				q.push(make_tuple(nx, ny, z + 1));
			}
		}
	}
	return -1;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= M; ++j) {
			scanf("%1d", &map[i][j]);
		}
    }
	cout << BFS() << "\n";
	return 0;
}