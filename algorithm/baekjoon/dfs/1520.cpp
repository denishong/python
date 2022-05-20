/*1520 내리막길 */
#include<iostream>
#include<memory.h>
using namespace std;

#define MAXN (int)5e2+10
int M,N;//행,열 
int map[MAXN][MAXN];
int visited[MAXN][MAXN]={0,};//방문 표시
int dy[]={-1,1,0,0};//상하좌우
int dx[]={0,0,-1,1};
bool isInside(int a, int b){
	return ( (a>=0) && (a<M) && (b>=0) && (b<N));
}
int DFS(int y, int x){
	if(y==M-1 && x==N-1) return 1;
	if(visited[y][x]!=-1) return visited[y][x];
	visited[y][x]=0;
	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isInside(ny,nx)){
			if(map[ny][nx]<map[y][x])
				visited[y][x]+=DFS(ny,nx);
		}
	}
	cout<<"y,x,visited: "<<y<<' '<<x<<' '<<visited[y][x]<<endl;
	return visited[y][x];
}
void InputData(){
	cin>>M>>N;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}
	memset(visited,-1,sizeof(visited));
}
int main(){
	InputData();
	cout<<DFS(0,0);
	return 0;
}
