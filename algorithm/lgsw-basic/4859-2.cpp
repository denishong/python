#include <bits/stdc++.h>
using namespace std;

#define MAXN 25
int N,house,cnt;
char mmap[MAXN+10][MAXN+10];
int sol[MAXN*MAXN];
int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};
bool isInside(int a, int b){
	return ((a>=1) && (a<=N) && (b>=1) && (b<=N));}

void InputData(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> &mmap[i][1];
	}
}
bool comp(int a, int b) {return a < b;}
void OutputData(){
	sort(sol, sol+cnt, comp);
	cout << cnt << endl;
	for(int i=0; i<cnt; i++){
		cout << sol[i] << endl;
	}
}
void DFS(int y, int x){
	if(mmap[y][x] !='1') return;
	mmap[y][x] = '0';
	house++;

	for(int i=0; i<4; i++){
		DFS(y+dy[i], x+dx[i]);	
	}

}
void BFS(int y, int x){
	int ny, nx;
	queue <pair<int,int>> q;
	q.push(pair<int,int>(y,x));
	mmap[y][x] = '0';

	while(!q.empty()){
		y=q.front().first;
		x=q.front().second;
	    q.pop();	
		for(int i=0; i<4; i++){
			ny=y+dy[i];
			nx=x+dx[i];
			if( isInside(ny, nx) && mmap[ny][nx] =='1' ){
				house++;
				q.push(pair<int,int>(ny,nx));
			}
		}

	}

}
void Solve(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(mmap[i][j] =='1'){ 
			house=0;
			BFS(i,j);
			sol[cnt++]=house;
			}
		}
	}
}
int main(){
	InputData();
	Solve();
	OutputData();
	return 0;
}
