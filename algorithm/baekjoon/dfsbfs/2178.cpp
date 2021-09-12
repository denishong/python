/*baekjoon 2178 미로탐색 BFS*/
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

#define max 100 

int n, m ;// 세로 ,가로  
int map[max][max] = {0, };
int mapCheck[max][max] = {0, };
int sizApt[323] = {0, };
int cnt;
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};

bool isInside(int a, int b){
	return (a>=0 && a<n) && (b>=0 && b<m);
}


void BFS(){

	int cur_y = 0, cur_x = 0;
	queue<pair<int,int>> q;
	q.push(pair<int, int>(cur_y, cur_x));
	mapCheck[cur_y][cur_x] = 1;

	while(!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + d[i][0];
			int next_x = cur_x + d[i][1];

		cout << "cur_y, cur_x, next_y, next_x " << cur_y << cur_x << next_y << next_x << endl;
			if(isInside(next_y , next_x ) && mapCheck[next_y][next_x] == 0 &&  map[next_y][next_x]){
				mapCheck[next_y][next_x] = mapCheck[cur_y][cur_x] + 1;
				q.push( pair<int, int>(next_y, next_x) );
			}
		}
	}

}

void Solution(int n){
	cnt = 0;
	BFS();


	cout << mapCheck[n-1][m-1] << endl;
#if 0
	cout << endl << endl;
	for( int i=0; i < n; i++){
		for( int j=0; j < m; j++){
			cout << mapCheck[i][j];
		}
		cout << endl;
	}
#endif


}

void Print(){
	printf("%d\n", cnt);
	for(int i=0; i < cnt; i++){
		printf("%d\n", sizApt[i]);
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	scanf("%d %d", &n, &m);
	for( int i=0; i < n; i++){
		for( int j=0; j < m; j++){
			scanf("%1d", &map[i][j] );
		}
	}

	Solution(n);

	return 0;
}
/*baekjoon 2178 미로탐색 BFS*/
