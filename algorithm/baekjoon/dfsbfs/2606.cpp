/*baekjoon 2606 virus*/
#include <iostream>
#include <queue>

using namespace std;
#define max 1001

int n, m, start;// 정점수 , 간선수 , 시작점 
int mat[max][max] = {0, };
int count;

bool visited[max] = { false, };

void init(){
	for ( int i =0; i <= 1000; i++) { visited[i] = false;}
	count=0;
}


void DFS(int st){
	visited[st] = true;
	//cout << st << " ";
	count++;
	for (int i = 1; i <= n; i++) {
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
		cout << temp << " " << endl;
		q.pop();
		for (int i = 1; i <= n; i++) {
			cout << "temp, i, mat[temp][i] , visited[i]" << temp << " "\
				<< i << ' ' << mat[temp][i] << ' ' << visited[i] << endl;
			if (mat[temp][i] == 1 && visited[i] == false ){
				visited[i] = true;
				q.push(i);
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int start = 1;
	cin >> n >> m ;


	for( int i=0; i < m; i++){
		int x,y;
		cin >> x >> y;
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

#if 0
	for( int i=1; i <= n; i++){
		for( int j=1; j <= n; j++){
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
#endif

	//cout << "DFS start!!" << '\n';
	init();
	BFS(start);
	cout << count-1 << endl;

	return 0;
}
/*baekjoon 2606 virus*/
