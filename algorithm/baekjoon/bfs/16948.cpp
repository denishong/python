/*baekjoon 16234 인구이동*/
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

#define MAXN 200 

int N;// map(NxN)
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
int dy[]={-2,-2,0,0,2,2};
int dx[]={-1,1,-2,2,-1,1};
bool isInside(int a, int b){
	return ((a>=0) && (a<N) && (b>=0) && (b<N));
}
int sy,sx,ey,ex;
void Solve(int sy, int sx, int ey, int ex){
	int x,y;
	queue<tuple<int,int>>q;
	memset(visited, -1, sizeof(visited));
	visited[sy][sx] = 0;
	q.push({sy,sx});

	while(!q.empty()) {
		tie(y,x)= q.front();
		q.pop();
		for(int i=0; i<6; i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInside(ny,nx) && visited[ny][nx]==-1){
				visited[ny][nx]=visited[y][x]+1;
				q.push({ny,nx});
			}
		}
	}
	
	cout<<visited[ey][ex]<<endl;
}
void InputData(){
	cin>>N;
	cin>>sy>>sx>>ey>>ex;
}
int main(){
	InputData();
	Solve(sy,sx,ey,ex);
	return 0;
}
