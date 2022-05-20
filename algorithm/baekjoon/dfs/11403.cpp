#include<iostream>
using namespace std;
#define MAXN (int)1e2+5
int N;//행,열 
int map[MAXN][MAXN];
int visited[MAXN][MAXN];//방문 표시
int answer[MAXN][MAXN];//방문 표시

void DFS(int p,int x, int y){
	visited[p][y]=true;
	answer[p][y]=1;
	for(int i=0; i<N; i++){
		if(visited[p][i]==false && map[y][i]==1)
			DFS(p,y,i);
	}

}
void Solve(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]==0 && map[i][j]==1)
				DFS(i,i,j);
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<answer[i][j]<<' '; 
		}
		cout<<endl;
	}
}
void InputData(){
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
