/*baekjoon 2667 DFS,BFS 단지번호 붙이기*/
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

#define max 25 

int n, m ;// 정점수 , 간선수 , 시작점 
int map[max][max] = {0, };
int sizApt[323] = {0, };
int cnt;
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};

bool isInside(int a, int b){
	return (a>=0 && a<n) && (b>=0 && b<n);
}


void BFS(int a, int b, int mark){
	queue<pair<int,int>> q;
	q.push(pair<int, int>(a, b));
	map[a][b] = mark;

	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if(isInside(y + d[i][0] , x + d[i][1]) && map[y	+ d[i][0]][x + d[i][1]] == 1){
				BFS(y + d[i][0], x + d[i][1], mark);
			}
		}
	}

}

void Solution(int n){
	cnt = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] == 1 ){
				BFS(i, j, cnt+2 );
				cnt++;
			}
		}
	}

	for( int i =0; i <n; i++){
		for(int j =0; j<n; j++){
			if( map[i][j] == 0) continue;
			sizApt[map[i][j]-2]++;
		}
	}
#if 0
	cout << endl << endl;
	for( int i=0; i < n; i++){
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
		printf("%d\n", sizApt[i]);
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	scanf("%d", &n);
	for( int i=0; i < n; i++){
		for( int j=0; j < n; j++){
			scanf("%1d", &map[i][j] );
		}
	}

	Solution(n);
	sort(sizApt, sizApt+cnt);
	Print();

	return 0;
}
/*baekjoon 2667 DFS,BFS 단지번호 붙이기*/
