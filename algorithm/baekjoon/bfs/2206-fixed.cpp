#include <iostream>
#include <queue>

using namespace std;
#define MAX 1000
int N, M;
int MAP[MAX][MAX];
int MAPCheck[MAX][MAX];
bool visited[MAX][MAX][2];
queue<pair<pair<int, int>, pair<int, int>>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Print_mapCheck(){
    for( int i=0; i < N; i++){
        for( int j=0; j < M; j++){
            printf("%d",  MAPCheck[i][j]);
        }
        printf("\n");
    }
}

int bfs() {
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));//cnt 1부터 시작
	visited[0][0][0] = true;
    MAPCheck[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wallBreak = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1)return cnt;
		for (int i = 0; i < 4; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];

			if (cx < 0 || cy < 0 || cx >= N || cy >= M)continue;
			if (MAP[cx][cy] == 0 && !visited[cx][cy][wallBreak]) {
				visited[cx][cy][wallBreak] = true;
                MAPCheck[cx][cy] = MAPCheck[cx][cy] + 1;
				q.push(make_pair(make_pair(cx, cy), make_pair(wallBreak, cnt + 1)));
			}
			if (MAP[cx][cy] == 1 && wallBreak == 0) {
				visited[cx][cy][1] = true;
                MAPCheck[cx][cy] = MAPCheck[cx][cy] + 1;
				q.push(make_pair(make_pair(cx, cy), make_pair(wallBreak + 1, cnt + 1)));

			}
		}

	}
	return -1;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &MAP[i][j]);
		}

    Print_mapCheck();
	cout << bfs() << "\n";

	return 0;
}
