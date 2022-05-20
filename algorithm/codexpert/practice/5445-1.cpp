#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAXN (30)

int L, R, C;
char map[MAXN+10][MAXN+10][MAXN+10];
int visit[MAXN+10][MAXN+10][MAXN+10];
int dl[6] = {0,0,0,0,-1,1};
int dr[6] = {-1,1,0,0,0,0};
int dc[6] = {0,0,1,-1,0,0};
bool isInside(int z, int y,int x){
	return ((z>=0 && z<L) && (y>=0 && y<R) && (x>=0 && x<C));
}
int sl,sr,sc;
int el,er,ec;
int cnt=0;
bool InputData(){
	cin >> L >> R >> C;
	if ((L == 0) && (R == 0) && (C == 0)) return false;
	//memset(map,0,sizeof(map));
	for (int l=0; l<L;l++){
		for (int r=0; r<R; r++){
			cin >> map[l][r];
		}
	}
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
	return true;
}
int BFS(int l, int r, int c){
	int nl,nr,nc;
	queue<pair<pair<int,int>,int>>q;
	q.push(make_pair(make_pair(l,r),c));
	map[l][r][c]='@';
	visit[l][r][c]=1;
	while(!q.empty()){
		l=q.front().first.first;
		r=q.front().first.second;
		c=q.front().second;
		q.pop();
		if( l==el && r==er && c==ec) return visit[l][r][c];
		for(int i=0; i<6; i++){
			nl=l+dl[i];
			nr=r+dr[i];
			nc=c+dc[i];
			
			if(isInside(nl,nr,nc) && map[nl][nr][nc]=='.' ){
				visit[nl][nr][nc]=visit[l][r][r]+1;
				cout << "l,r,c, visit[l][r][c]" <<l << ' ' << r << ' ' << c << ' '<<  visit[l][r][c] << endl;
				cout << "nl, nr, nc,visit[nl][nr][nc]:" << nl << ' ' << nr << ' ' << nc << ' ' << visit[nl][nr][nc] << endl;
				map[nl][nr][nc]='@';
				q.push(make_pair(make_pair(nl,nr),nc));
				cnt++;
			}
		}

	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	while(InputData()){

		ans=BFS(sl,sr,sc);
		cout << "ans: " << ans << endl;
		if (ans == -1) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << ans << " minute(s)." << "\n";
	}
	return 0;
}
