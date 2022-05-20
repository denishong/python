#include <iostream>
using namespace std;
#define MAXN ((int) 1e2)
char map[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int N,M;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int Min=10001;
bool inRange(int y, int x){
	return (y>=1 && y<=N && x>=1 && x<=M);}

void DFS(int y, int x,int d){
	if(!inRange(y,x)) return;

	if(y==N && x==M){
		if(d<Min)
			Min=d;
		return;
	}
	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(visited[ny][nx]==0 && map[ny][nx]=='1'){
			visited[ny][nx]= 1;
			DFS(ny, nx, d+1);
			visited[ny][nx]=0; 
		}
	}
}
void InputData(){
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		cin >> &map[i][1];
}
int main(void){
	InputData();
	DFS(1,1,1);
	cout<<Min<<endl;
	return 0;
}
