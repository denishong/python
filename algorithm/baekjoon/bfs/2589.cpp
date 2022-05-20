#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define MAXN (50)
int N, M;//세로, 가로
char map[MAXN+10][MAXN+10];//지도정보
int visited[MAXN+10][MAXN+10];//방문 표시 
struct Q{
	int y,x,t;
};
int count=0,ans=-1;
int BFS(int y, int x,int t){
	queue<Q>q;
	int dy[]={-1,1,0,0};//동서남북
	int dx[]={0,0,-1,1};
	//1.초기화 
	count=0;
	q={};
	//2.큐에 초기값 저장 
	q.push({y,x,t});	
	//3.반복문 
	while(!q.empty()){
		Q cur=q.front();q.pop();
		visited[y][x]=1;

		for(int i=0; i<4; i++){
			t=cur.t;
			int ny=cur.y+dy[i];
			int nx=cur.x+dx[i];
			if((ny<0) || (ny>=N) || (nx<0) || (nx>=M) || map[ny][nx]!='L') continue;
			if(visited[ny][nx]==0){
				visited[ny][nx]=1;
				q.push({ny,nx,t+1});
				count=t+1;
				if(ans<count) ans=count;//ans에 최대값 업데이트 
			}
		}
	}
	return ans;
}
void Solve(){
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if(map[i][j]=='L'){
				ans=BFS(i,j,0);
				memset(visited,false,sizeof(visited));
			}
		}
	}
	cout<<ans<<endl;
}
void InputData(){
	cin>>N>>M;
	for (int i=0; i<N; i++){
		cin>>map[i];
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
