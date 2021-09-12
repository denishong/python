#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 1e2)
char mat[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int N,M;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
bool inRange(int y, int x){
	return (y>=1 && y<=N && x>=1 && x<=M);}
void InputData(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		cin >> &mat[i][1];
	}
}

void OutputData(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
}
int Solve(){
	int y,x, ny,nx;
	queue <pair<int,int>> q;
	q.push(pair<int,int>(1,1));
	visited[1][1] = 1;

	while(!q.empty()){
		y= q.front().first;
		x= q.front().second;
		q.pop();
		if(y==N && x==M) return visited[y][x];
	for(int i=0; i<4; i++){
		ny= y+dy[i];
		nx= x+dx[i];
		if(inRange(ny,nx) && visited[ny][nx]==0 && mat[ny][nx]=='1'){
			visited[ny][nx]= visited[y][x]+1;
			q.push(pair<int,int>(ny,nx));
		}
	}	
	}
	return 0;
}
int main(void){
	int ans=0;
	InputData();
	ans=Solve();
	cout << ans;
	return 0;
}
