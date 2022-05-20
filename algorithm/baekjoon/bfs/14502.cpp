#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAXN (int)10
int map[MAXN][MAXN];
int tmp[MAXN][MAXN];//방문 표시
int N,M;//행,열 
int dy[]={-1,1,0,0};//상하좌우
int dx[]={0,0,-1,1};
struct Q{
	int y,x;
};
queue<Q>q;
vector<Q>v;
int sol=0;
bool isInside(int a, int b){
	return ( (a>=0) && (a<N) && (b>=0) && (b<M));
}
void FloodFill(int y, int x){
	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isInside(ny,nx) && tmp[ny][nx]==0){
			tmp[ny][nx]=2;
			FloodFill(ny,nx);
		}	
	}

}
int checkCount(){	
	int count=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tmp[i][j]==2){
				FloodFill(i,j);
			}
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tmp[i][j]==0)
				count++;
		}
	}
	return count;
}
void copymap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			tmp[i][j]=map[i][j];
		}
	}
}
	
void DFS(int x, int d){
	if(d==3){
		copymap();
		sol=max(sol,checkCount());
		return;
	}
	for(int i=x; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==0){
				map[i][j]=1;
				DFS(i,d+1);
				map[i][j]=0;
			}
		}
	}

}
void InputData(){
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				v.push_back({i,j});
			}
		}
	}
}
int main(){
	InputData();
	DFS(0,0);
	cout<<sol<<endl;
	return 0;
}