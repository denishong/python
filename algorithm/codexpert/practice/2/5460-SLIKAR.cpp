#include <iostream>
#include <queue>
using namespace std;
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];
struct Q{
	int r,c,t,type;
};
int BFS(){
	int dr[]={-1,1,0,0};
	int dc[]={0,0,-1,1};
	queue<Q>q;
	int sr,sc;
	//1.큐 초기화 
	q={};
	//2.초기값 큐에 저장 
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j]=='*') {//0: 홍수지역 1:화가 
				q.push({i,j,0,0});
			}else if(map[i][j]=='S'){
				sr=i, sc=j;
			}
		}
	}
	q.push({sr,sc,0,1});//화가 마지막으로 저장 
	//3.반복문 
	while(!q.empty()){
		Q cur=q.front(); q.pop();
		for(int i=0; i<4; i++){
			int nr=cur.r+dr[i];
			int nc=cur.c+dc[i];
			if( (nr<0) || (nr>=R) || (nc<0) || (nc>=R) ) continue;//범위를 벗어난 경우 
			if(cur.type==0){
				if(map[nr][nc]=='D') continue;//홍수는 비버를 지나갈 수 없다 
				q.push({nr,nc,cur.t+1,0});
				map[nr][nc]='*';
			}else if(cur.type==1){
				if(map[nr][nc]=='D') return cur.t+1; //목적지 도착 
				if(map[nr][nc]=='S') continue; //화가 간 곳은 갈 수 없다 
				q.push({nr,nc,cur.t+1,1});
				map[nr][nc]='S';
			}
		}
	}
	//4.실패 
	return -1;
}
void InputData(){
	cin >> R >> C;
	for (int i=0; i<R; i++){
		cin >> map[i];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, ans = -10;
	cin >> T;
	for (int t=1; t<=T; t++){
		InputData();//입력 받는 부분

		ans=BFS();// 여기서부터 작성 

		if (ans == -1) cout << "KAKTUS" << "\n";//출력 하는 부분
		else cout << ans << "\n";
	}
	return 0;
}
