#include<iostream>
#include<memory.h>
using namespace std;
#define MAXN (int)3e2
int map[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int remap[MAXN+10][MAXN+10];
int N,M;//행,열 
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
bool isInside(int a, int b){
	return ( (a>=1) && (a<N-1) && (b>=1) && (b<M-1));
}
void DFS(int y, int x){	
	visited[y][x]=true;
	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isInside(ny,nx) && map[ny][nx] && visited[ny][nx]==false){
		//cout<<"test:ny,nx"<<ny<<' '<<nx<<endl;
			DFS(ny,nx);
		}
	}
}
void remapping(){
	for(int i=1; i<N-1; i++){
		for(int j=1; j<M-1; j++){
			remap[i][j]=map[i][j];
		}
	}

	
	for(int y=1; y<N-1; y++){
		for(int x=1; x<M-1; x++){
			if(remap[y][x]){
				int cnt=0;
				for(int i=0; i<4; i++){
					int ny=y+dy[i];
					int nx=x+dx[i];
					if(remap[ny][nx]==0)
						cnt++;	
				}
				map[y][x]=max(remap[y][x]-cnt,0);
			}	
		}
	}
		

}
void Solve(){
	int cnt,year=0;
	while(1){
	cnt=0;
	bool result=false;
	memset(visited,false,sizeof(visited));
	for(int i=1; i<N-1; i++){
		for(int j=1; j<M-1; j++){
			if(map[i][j] && visited[i][j]==false){
				//cout <<"cnt:"<< cnt<<endl;
				cnt++;
				if(cnt==2){
					result=true;
					break;
				}
				DFS(i,j);
			}
		}
	}
		if(result)
			break;
		if(cnt==0){
			year=0;
			break;
		}
		remapping();
		year++;
	}
	cout << year<<endl;

}
void InputData(){
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
