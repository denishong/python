/*baekjoon 1012 유기농 배추 */
#include <iostream>
#include <queue>

using namespace std;

#define max 50 

int t;// test case
int m,n, k ;//가로, 세로 , 배추 수 
int map[max][max];
int cnt;
int x,y;
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};

bool isInside(int a, int b){
	return (a>=0 && a<m) && (b>=0 && b<n);
}


void bfs(int a, int b ){
	queue<pair<int,int>> q;
	q.push(pair<int, int>(a, b));
	map[a][b] = 2;

	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		cout << "y, x : " << y << x << endl;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if(isInside(y + d[i][0] , x + d[i][1]) && map[y	+ d[i][0]][x + d[i][1]] == 1){
				q.push(pair<int, int>(y + d[i][0], x + d[i][1]));
				cout << "push( y+d[i][1], x+d[i][0] ) : " << y + d[i][0] << x + d[i][1] << endl;
				map[y + d[i][0]][x + d[i][1]] = 2;
			}
		}
	}

}

void Solution(){
	cnt = 0;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] == 1 ){
				bfs(i, j);
				cnt++;
				cout << "i, j, cnt : " << i << j << cnt << endl;
			}
		}
	}

	cout << "cnt : " << cnt << endl;

#if 1
	cout << endl << endl;
	for( int i=0; i < m; i++){
		for( int j=0; j < n; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
#endif


}

void Print(){
	printf("%d\n", cnt);
	for(int i=0; i < cnt; i++){
		//printf("%d\n", sizApt[i]);
	}
}

void test_print(){

	cout << endl;
	for( int i=0; i < m; i++){
		for( int j=0; j < n; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

void init_map(){

	cout << endl;
	for( int i=0; i < m; i++){
		for( int j=0; j < n; j++){
			map[i][j] = 0;
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for( int l=0; l < t; l++ ) {
		cin >> m >> n >> k;
		cout << "m : " << m << "n : " << n << "k : " << k << endl;
		for( int i=0; i < k; i++){
			cin >> y >> x;
			//cout << y << x << endl;
			map[y][x] = 1;
		}

		test_print();
		Solution();
		init_map();
	}

	return 0;
}
/*baekjoon 1012 유기농 배추 */
