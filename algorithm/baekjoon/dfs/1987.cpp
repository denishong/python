#include<iostream>
using namespace std;
#define MAXN (int)2e1+10
char map[MAXN][MAXN];
int visited[MAXN*MAXN];//알파벳 방문 표시visited[0]='A'-'A'
int R,C;//행,열
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int sol;
bool isInside(int a, int b){
	return ( (a>=0) && (a<R) && (b>=0) && (b<C));
}
void DFS(int y, int x, int t){

	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isInside(ny,nx) && visited[map[ny][nx]-'A']==0){
			cout<<ny<<' '<<nx<<' '<<map[ny][nx]<<' '<<t<<endl;
			visited[map[ny][nx]-'A']=1;
			DFS(ny,nx,t+1);
			visited[map[ny][nx]-'A']=0;
		}
	}
	if(sol<t) sol=t;
}
void InputData(){
	cin>>R>>C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin>>map[i][j];
		}
	}
}
int main(){
	sol=0;
	InputData();
	//visited[map[0][0]-'A']=1;
	DFS(0,0,1);
	cout<<sol<<endl;
	return 0;
}
