#include <iostream>
#include <queue>
using namespace std;

#define MAXN (30)

int L, R, C;
char map[MAXN+10][MAXN+10][MAXN+10];
struct DATA{
	int l,r,c,t;
};
int sl,sr,sc,el,er,ec;
queue<DATA>q;
void push(int l,int r,int c, int t){
	if(map[l][r][c]!='.') return; //빈공간 아님(#:장애물, 0:범위 벗어남, @:이미 방문했음)
	map[l][r][c]='@';//방문표시 
	q.push({l,r,c,t});
}
int BFS(){
	int l,r,c,t,nl,nr,nc;
	int dl[]={0,0,0,0,-1,1};
	int dr[]={-1,1,0,0,0,0};
	int dc[]={0,0,-1,1,0,0};
	//1.초기화 
	//2.시작 위치 큐에 저장 
	push(sl,sr,sc,0);
	//3.반복문 
	while(!q.empty()){
		DATA cur=q.front();
		q.pop();
		if(cur.l==el && cur.r==er && cur.c==ec) return cur.t;
		for(int i=0; i<6; i++){
			push(cur.l+dl[i], cur.r+dr[i], cur.c+dc[i], cur.t+1);
		}
	}
	//4.실패 
	return -1;
}
bool InputData(){
	cin >> L >> R >> C;
	if ((L == 0) && (R == 0) && (C == 0)) return false;
	for (int l=0; l<L;l++){
		for (int r=0; r<R; r++){
			cin >> map[l][r];
			for(int c=0; c<C; c++){
				if(map[l][r][c]=='S'){
					sl=l,sr=r,sc=c;
					map[l][r][c]='.';
				}else if(map[l][r][c]=='E'){
					el=l,er=r,ec=c;
					map[l][r][c]='.';
				}			
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	while(InputData()){

		ans=BFS();//여기서부터 작성

		if (ans == -1) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << ans << " minute(s)." << "\n";
	}
	return 0;
}
