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
	return ((z>=1 && z<=L) && (y>=1 && y<=R) && (x>=1 && x<=C));
}
int sl,sr,sc;
int el,er,ec;
bool InputData(){
	cin >> L >> R >> C;
	if ((L == 0) && (R == 0) && (C == 0)) return false;
	memset(map,0,sizeof(map));
	for (int l=1; l<=L;l++){
		for (int r=1; r<=R; r++){
			cin >> map[l][r][1];
			for(int c=1; c<=C; c++){
				if(map[l][r][c]=='S'){
			cout << " sl:sr:sc" << sl << ' ' << sr << ' ' << sc << endl;
					sl=l; sr=r; sc=c;
					map[l][r][c]='.';
				}else if(map[l][r][c]=='E'){
			cout << " el:er:ec" << el << ' ' << er << ' ' << ec << endl;
					sl=l; sr=r; sc=c;
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
	cout << " l:r:c" << l << ' ' << r << ' ' << c << endl;	
	visit[l][r][c]=1;
	while(!q.empty()){
		l=q.front().first.first;
		r=q.front().first.second;
		c=q.front().second;
		q.pop();
		for(int i=0; i<6; i++){
			nl=l+dl[i];
			nr=r+dr[i];
			nc=c+dc[i];
			
			if( (nl==el) && nr==er &&  nc==ec) return visit[l][r][c];
			if(isInside(nl,nr,nc) && map[nl][nr][nc]=='.' && visit[nl][nr][nc]==0){
				cout << visit[l][r][c] << endl;
				visit[nl][nr][nc]=visit[l][r][r]+1;
				q.push(make_pair(make_pair(nl,nr),nc));
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

		//ans=BFS(sl,sr,sc);
		cout << "ans: " << ans << endl;
		if (ans == -1) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << ans << " minute(s)." << "\n";
	}
	return 0;
}
