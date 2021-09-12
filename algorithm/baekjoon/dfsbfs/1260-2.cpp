/*baekjoon 1260 DFS,BFS*/
#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001

int N, M, V;// 정점수 , 간선수 , 시작점 
int mat[MAX][MAX] = {0, };
bool visited[MAX] = { false, };

void init(){
	for ( int i =0; i <= N; i++) { visited[i] = false;}
}
void DFS(int st){
	visited[st] = true;
	cout << st << " ";
	for (int i = 1; i <= N; i++) {
	//	cout << "st, i, mat[st][i] , visited[i]" << st << " "\
			<< i << ' ' << mat[st][i] << ' ' << visited[i] << endl;
		if (mat[st][i] == 1 && visited[i] == false )
			DFS(i);
	}

}

void BFS(int st){
	queue<int> q;
	visited[st] = true;
	q.push(st);

	while(!q.empty()) {
		int temp = q.front();
		cout << temp << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
	//		cout << "st, i, mat[temp][i] , visited[i]" << st << " "\
				<< i << ' ' << mat[temp][i] << ' ' << visited[i] << endl;
			if (mat[temp][i] == 1 && visited[i] == false ){
				visited[i] = true;
				q.push(i);
			}
		}
	}

}

void InputData(){
	int x,y;

	cin >> N >> M >> V;

	for( int i=0; i < M; i++){
		cin >> x >> y;
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

}
void OutputData(){
	for( int i=1; i <= N; i++){
		for( int j=1; j <= N; j++){
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	InputData();
	DFS(V);
	init();
	cout << endl;
	BFS(V);

	return 0;
}
/*baekjoon 1260 DFS,BFS*/
