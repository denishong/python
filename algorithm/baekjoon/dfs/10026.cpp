#include<iostream>
#include<memory.h>
using namespace std;
#define MAXN (int)1e2+10
char map[MAXN][MAXN];
int visited[MAXN][MAXN];//방문 표시
int N;//행,열 
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
bool isInside(int a, int b){
	return ( (a>=0) && (a<N) && (b>=0) && (b<N));
}
bool DFS(int y, int x, char c){	
	
	if(isInside(y,x) && visited[y][x]==0 && map[y][x]==c){
		visited[y][x]=1;
		for(int i=0; i<4; i++){
			DFS(y+dy[i],x+dx[i],c);
			//cout<<y+dy[i]<<' '<<x+dx[i]<<endl;
		}	
		return true;
	}else{
		return false;
	}
}
int Calc(int c){
	int cnt=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j]==c)
				cnt+=DFS(i,j,c);
		}
	}
	return cnt;
}
void remap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j]=='R')
				map[i][j]='G';
		}
	}
}
void Solve(){
	int cnt1=0,cnt2=0;
	cnt1+=Calc('R');
	cnt1+=Calc('G');
	cnt1+=Calc('B');
	memset(visited,false,sizeof(visited));
	remap();
	cnt2+=Calc('G');
	cnt2+=Calc('B');
	cout<<cnt1<<' '<<cnt2<<endl;
}
void InputData(){
	cin>>N;
	for(int i=0; i<N; i++){
			cin>>map[i];
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
