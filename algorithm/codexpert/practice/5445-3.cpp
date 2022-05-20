#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAXN (30)

int L, R, C;
char map[MAXN+10][MAXN+10][MAXN+10];
int dl[6] = {0,0,0,0,-1,1};
int dr[6] = {-1,1,0,0,0,0};
int dc[6] = {0,0,1,-1,0,0};
bool isInside(int z, int y,int x){
	return ((z>=0 && z<L) && (y>=0 && y<R) && (x>=0 && x<C));
}
int sl,sr,sc;
int el,er,ec;
int cnt=0;
struct DATA{
	int l;
	int r;
	int c;
	int t;
};
int BFS(){
	int l,r,c,t;
	int nl,nr,nc;
	DATA tmp;
    //0.시작,도착위치 찾기 
	for (int l=0; l<L;l++){
		for (int r=0; r<R; r++){
			for (int c=0; c<C; c++){
				if( map[l][r][c]=='S') {
					sl=l; sr=r; sc=c;
					map[l][r][c]='.';
				}
				if( map[l][r][c]=='E') {
					el=l; er=r; ec=c;
					map[l][r][c]='.';
				}
			}
		}
	}
    //1.초기화 
	queue<DATA>q;
    //2.시작위치 큐에 저장 
	tmp.l=sl;tmp.r=sr;tmp.c=sc;	tmp.t=0;
	q.push(tmp);
	map[sl][sr][sc]='@';
    //3.반복문
	while(!q.empty()){
		tmp=q.front();
		l=tmp.l;r=tmp.r;c=tmp.c;t=tmp.t;
		q.pop();
		if( l==el && r==er && c==ec) return t;
		for(int i=0; i<6; i++){
			nl=l+dl[i];
			nr=r+dr[i];
			nc=c+dc[i];
			
			if(isInside(nl,nr,nc) && map[nl][nr][nc]=='.' ){
				map[nl][nr][nc]='@';
				tmp.l=nl;tmp.r=nr; tmp.c=nc; tmp.t=t+1;
				q.push(tmp);
			}
		}

	}
    //4.실패
	return -1;
}
bool InputData(){
	cin >> L >> R >> C;
	if ((L == 0) && (R == 0) && (C == 0)) return false;
	memset(map,0,sizeof(map));
	for (int l=0; l<L;l++){
		for (int r=0; r<R; r++){
			cin >> map[l][r];
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

		ans=BFS();
		if (ans == -1) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << ans << " minute(s)." << "\n";
	}
	return 0;
}
