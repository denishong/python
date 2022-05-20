/*baekjoon 16234 인구이동*/
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

#define MAXN 51

int N, L, R;// map(NxN), L명 이상, R명 이하  
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
bool isInside(int a, int b){
	return ((a>=0) && (a<N) && (b>=0) && (b<N));
}
bool moveOK(int y, int x){
	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isInside(ny,nx)) continue;
		if(abs(map[y][x]-map[ny][nx])>=L && abs(map[y][x]-map[ny][nx])<=R) return true;
	}
	return false;
}
bool openOK(int y, int x, int ny, int nx){
	if(abs(map[y][x]-map[ny][nx])>=L && abs(map[y][x]-map[ny][nx])<=R) return true;
	else return false;
}
void BFS(int y, int x){
	int sum=0, cnt=0;
	queue<tuple<int,int>>q,sq;
	visited[y][x] = 1;
	q.push({y,x});

	while(!q.empty()) {
		tie(y,x)= q.front();
		sq.push(q.front());
		q.pop();
		sum+=map[y][x];
		cnt++;
		for(int i=0; i<4; i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInside(ny,nx) && visited[ny][nx]==0 && openOK(y,x,ny,nx)){
				visited[ny][nx]=1;
				q.push({ny,nx});
			}
		}
	}
	int tmp=sum/cnt;
	while(!sq.empty()){
		tie(y,x) = sq.front();
		sq.pop();
		map[y][x]=tmp;
	}

}
bool Check=true;
void Solve(){
	int Day=0;
	while(Check){
		Check=false;
		for( int i=0; i < N; i++){
		for( int j=0; j < N; j++){
			if(visited[i][j]==0 && moveOK(i,j)){
				BFS(i,j);
				Check=true;
			}
		}
		}
		if(Check==true) Day++;
		memset(visited,false, sizeof(visited));
	}//while
	cout<<Day<<endl;
}
void InputData(){
	int x,y;
	cin >> N >> L >> R;
	for( int i=0; i < N; i++){
		for( int j=0; j < N; j++){
			cin>>map[i][j];
		}
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
