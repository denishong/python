/*baekjoon 1012 유기농 배추 */
#include <iostream>
#include <queue>
using namespace std;

#define max 50 

int t;// test case
int m,n, k ;//가로, 세로 , 배추 수 
int map[max][max];
int cnt;
int cur_y, cur_x;
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};

bool isInside(int a, int b){
	return (a>=0 && a<m) && (b>=0 && b<n);
}


void bfs(int a, int b ){
	queue<pair<int,int>> q;
	q.push(pair<int, int>(a, b));
	map[a][b] = 2;

	while(!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + d[i][0];
			int next_x = cur_x + d[i][1];

			if(isInside(next_y, next_x ) && map[next_y][next_x] == 1){
				q.push(pair<int, int>(next_y , next_x ));
				map[next_y][next_x]  = 2;
			}
		}
	}

}

void Solve(){
	cnt = 0;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] == 1 ){
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

void Print(){
	printf("%d\n", cnt);
	for(int i=0; i < cnt; i++){
		//printf("%d\n", sizApt[i]);
	}
}

void printMap(){

	cout << endl;
	for( int i=0; i < m; i++){
		for( int j=0; j < n; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

void init_map(){

	for( int i=0; i < m; i++){
		for( int j=0; j < n; j++){
			map[i][j] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for( int l=0; l < t; l++ ) {
		cin >> m >> n >> k;
		for( int i=0; i < k; i++){
			cin >> cur_y >> cur_x;
			map[cur_y][cur_x] = 1;
		}
		Solve();
		init_map();
	}

	return 0;
}
/*baekjoon 1012 유기농 배추 */
