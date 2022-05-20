#include <iostream>
#include <queue>
using namespace std;
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];
int visit[MAXN+10][MAXN+10];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
struct Q{
	int r,c,t,type;//세로,가로,시간,종류(0:홍수,1:화가)
};
queue<Q>q;//세로,가로,시간,종류(0:홍수,1:화가)
void InputData(){
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> map[i];
    }
}
int Solve(){
    int ret=0;
    int r,c,nr,nc,t,type;
	//1.초기화
	q={};
	//2.시작위치 큐에 저장(홍수 먼저 저장한 후,마지막으로 화가)
	int sr=0,sc=0;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
        	if(map[i][j] == 'S'){//화가 
            	sr=i, sc=j;
        	}else if(map[i][j]=='*'){//홍수 
				q.push({i,j,0,0});
        	}
        }
    }
	q.push({sr,sc,0,1});
	//3.반복문 
    while(!q.empty()){
		Q cur=q.front();
        q.pop();

    	for(int i=0; i<4; i++){
        	nr=cur.r+dr[i];
        	nc=cur.c+dc[i];
			if((nr<0)||(nr>=R)||(nc<0)||(nc>=C)) continue;//범위를 벗어남 
			if((map[nr][nc]=='X') || (map[nr][nc]=='*')) continue;//바위나 홍수로 확산 안함 
			if(cur.type==0){//홍수 
				if(map[nr][nc]=='D') continue; //홍수는 비버굴로 확산 못함 
				q.push({nr,nc,cur.t+1,0});
				map[nr][nc]='*';//홍수로 방문 표시 
			}else{//화가 
				if(map[nr][nc]=='D') return cur.t+1; //도착 성공 
				if(map[nr][nc]=='S') continue; //화가가 지나온 곳 
				q.push({nr,nc,cur.t+1,1});
				map[nr][nc]='S';
			}
    	}
    }
	//4.실패 
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, ans = -10;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력 받는 부분

        ans=Solve();// 여기서부터 작성 
        if (ans == -1) cout << "KAKTUS" << "\n";//출력 하는 부분
        else cout << ans << "\n";
    }
    return 0;
}
