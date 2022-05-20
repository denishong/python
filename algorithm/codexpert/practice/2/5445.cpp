#include <iostream>
#include <queue>
using namespace std;

#define MAXN (30)

int L, R, C;
char map[MAXN+10][MAXN+10][MAXN+10];
int sl,sr,sc,el,er,ec;
struct Q{
	int l,r,c,t;
};
queue<Q>q;
void push(int l, int r, int c, int t){
	if(map[l][r][c]!='.')  return;
	map[l][r][c]='@';
	q.push({l,r,c,t});
}
int dl[]={0,0,0,0,-1,1};
int dr[]={0,0,-1,1,0,0};
int dc[]={-1,1,0,0,0,0};
int BFS(){
	//1.큐초기화 
	q={};
	//2.큐 초기값 입력 
	push(sl,sr,sc,0); //초기값 입력 	
	//3.반복문 
	while(!q.empty()){
	Q cur=q.front();
	q.pop();
	if((cur.l==el) && (cur.r==er) && (cur.c==ec)) return cur.t;
		for(int i=0; i<6; i++){
			int nl=cur.l+dl[i];
			int nr=cur.r+dr[i];
			int nc=cur.c+dc[i];
			if((nl<0) || (nl>=L) || (nr<0) || (nr>=R) ||(nc<0) ||(nc>=C)) continue;
			push(nl,nr,nc,cur.t+1);
		}
	}
	//4실패 	
	return -1;
}
int DFS(){
	//1.큐초기화 
	q={};
	//2.큐 초기값 입력 
	push(sl,sr,sc,0); //초기값 입력 	
	//3.반복문 
	while(!q.empty()){
	Q cur=q.front();
	q.pop();
	if((cur.l==el) && (cur.r==er) && (cur.c==ec)) return cur.t;
		for(int i=0; i<6; i++){
			int nl=cur.l+dl[i];
			int nr=cur.r+dr[i];
			int nc=cur.c+dc[i];
			if((nl<0) || (nl>=L) || (nr<0) || (nr>=R) ||(nc<0) ||(nc>=C)) continue;
			DFS(nl,nr,nc,cur.t+1);
		}
	}
	//4실패 	
	return -1;
}

bool InputData(){
	cin >> L >> R >> C;
	if ((L == 0) && (R == 0) && (C == 0)) return false;
	for (int l=0; l<L;l++){
		for (int r=0; r<R; r++){
			cin >> map[l][r];
			for (int c=0; c<C; c++){
				if(map[l][r][c]=='S') sl=l,sr=r,sc=c,map[l][r][c]='.';
				if(map[l][r][c]=='E') el=l,er=r,ec=c,map[l][r][c]='.';
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
