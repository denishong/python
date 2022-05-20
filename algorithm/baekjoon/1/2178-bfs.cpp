#include <iostream>
#include <queue>
using namespace std;
#define MAXN ((int) 1e2)
char map[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int N,M;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int Min=10001;
struct Q{
	int y,x,d;
};
bool isInside(int y, int x){
	return (y>=1 && y<=N && x>=1 && x<=M);}
int BFS(int y, int x,int d){
	queue<Q>q;
	//1.Q초기화 
	q={};
	//2.초기값 Q에 입력 
	q.push({y,x,d});
	//3.반복문 
	while(!q.empty()){
	Q curr=q.front();q.pop();

	if(curr.y==N && curr.x==M){
		return visited[N][M];
	}
	for(int i=0; i<4; i++){
		int ny=curr.y+dy[i];
		int nx=curr.x+dx[i];
		if(isInside(ny,nx) &&  map[ny][nx]=='1'){
			//visited[ny][nx]=visited[curr.y][curr.x]+1;
			q.push({ny, nx, curr.d+1});
		}
	}
	}//while
}
void InputData(){
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		cin >> &map[i][1];
}
int main(void){
	InputData();
	cout<<BFS(1,1,0)<<endl;
	return 0;
}
