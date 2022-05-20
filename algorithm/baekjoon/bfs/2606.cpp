/*baekjoon 2606 virus*/
#include <iostream>
#include <queue>

using namespace std;
#define MAXN 1001

int n, m ;// 정점수 , 간선수 
int count;
int map[MAXN][MAXN];
int visited[MAXN];

void DFS(int st){
	visited[st] = 1;
	count++;
	for (int i = 1; i <= n; i++) {
		if (map[st][i] == 1 && visited[i] == 0)
			DFS(i);
	}

}

void BFS(int st){
	queue<int> q;
	visited[st] = 1;
	q.push(st);

	while(!q.empty()) {
		int temp = q.front();
		cout << temp << " " << endl;
		q.pop();
		for (int i = 1; i <= n; i++) {
			cout << "temp, i, map[temp][i] , visited[i]" << temp << " "\
				<< i << ' ' << map[temp][i] << ' ' << visited[i] << endl;
			if (map[temp][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				q.push(i);
			}
		}
	}

}
void InputData(){
	cin >> n >> m ;
	for( int i=0; i < m; i++){
		int x,y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
}
int main(){
	InputData();
	count=0;
	DFS(1);
	cout << count-1 << endl;

	return 0;
}
/*baekjoon 2606 virus*/
