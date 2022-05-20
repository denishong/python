#include <iostream>
#include <queue>
using namespace std;
#define MAXN (100)
int H, W;//세로길이, 가로길이
int map[MAXN+10][MAXN+10];//지도정보
int sh, sw, sd;//시작 세로, 가로, 방향
int eh, ew, ed;//도착 세로, 가로, 방향
int visited[MAXN+10][MAXN+10][5];//방문 지도정보로 방향까지 포함한다 
struct Q{
	int h,w,d,t;
};
queue<Q>q;
void push(int h, int w, int d, int t){
	if(visited[h][w][d]==1) return;
	visited[h][w][d]=1;
	q.push({h,w,d,t});
}
void InputData(){
	cin >> H >> W;
	for (int i=1; i<=H; i++){
		for (int j=1; j<=W; j++){
			cin >> map[i][j];
		}
	}
	cin >> sh >> sw >> sd;
	cin >> eh >> ew >> ed;
}
int BFS(){
	int dh[]={0,0,0,1,-1};//1:동쪽 2:서쪽 3:남쪽 4:북쪽 
	int dw[]={0,1,-1,0,0};//1:동쪽 2:서쪽 3:남쪽 4:북쪽 
	//1.큐 초기화 
	q={};
	//2.초기값 큐에 저장 
	push(sh,sw,sd,0);
	//3.반복문
	while(!q.empty()){
		Q cur=q.front();
		q.pop();
		if((cur.h==eh) && (cur.w==ew) && (cur.d==ed) ) return cur.t;//도착지에 도착 
		//1.GO K
		for(int i=1; i<=3; i++){
			int nh=cur.h+dh[cur.d]*i;
			int nw=cur.w+dw[cur.d]*i;
			if((nh<1) || (nh>H) || (nw<1) || (nw>W) ) break;//범위 채크 	
			if(map[nh][nw] ==1) break;
			push(nh,nw,cur.d,cur.t+1);
		}
		//2.Turn(동:1, 서:2, 남:3, 북:4)
		if(cur.d>=3){//남북==>동서 
			push(cur.h,cur.w, 1, cur.t+1);
			push(cur.h,cur.w, 2, cur.t+1);
		}else{//동서==>남북 
			push(cur.h,cur.w, 3, cur.t+1);
			push(cur.h,cur.w, 4, cur.t+1);
		}
	}
	//4.실패 
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	InputData();// 입력받는 부분
	ans=BFS();// 여기서부터 작성
	cout << ans << "\n";// 출력하는 부분
	return 0;
}
