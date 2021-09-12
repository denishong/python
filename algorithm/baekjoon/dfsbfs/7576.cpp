/*baekjoon 7576 토마토 BFS*/
#include <iostream>
#include <queue>

using namespace std;

#define max 100 

int n, m ;// 정점수 , 간선수 , 시작점 
int map[max][max];
bool mapCheck[max][max];
int path[max][max];
int cnt;
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
queue<pair<int,int>> q;


bool isInside(int a, int b){
	return (a>=0 && a<n) && (b>=0 && b<m);
}

void bfs(){

	while(!q.empty()) {

		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + d[i][0];
			int next_x = cur_x + d[i][1];

			if(isInside(next_y , next_x) && map[next_y][next_x] == 0 && mapCheck[next_y][next_x] == 0 ){
				mapCheck[next_y][next_x] = 1;
				q.push( pair<int, int>(next_y, next_x) );
				path[next_y][next_x] = path[cur_y][cur_x] + 1;
			}
		}
	}

}
void OutputData(){
	for( int i=0; i < n; i++){
		for( int j=0; j < m; j++){
			cout << path[i][j] << ' ';
		}
        cout << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for( int i=0; i < n; i++){
		for( int j=0; j < m; j++){
			cin >> map[i][j];
			if( map[i][j] == 1 ){
				q.push(pair<int,int>(i, j)); 
			}
		}
	}


	bfs();

    OutputData();
	for( int i=0; i < n; i++){
		for( int j=0; j < m; j++){
			if( map[i][j] == 0 && path[i][j] == 0 ){
				cout << -1 << endl;	
				return 0;
			}
		}
	}

	int ans = -1;
	for( int i=0; i < n; i++){
		for( int j=0; j < m; j++){
			if( path[i][j] > ans ){
				ans = path[i][j];	
			}
		}
	}
	cout << ans << endl;

	return 0;
}
/*baekjoon 7576 토마토 BFS*/
