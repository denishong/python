#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
#define INF (int)1e3;
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보
int visit[MAXN+10][MAXN+10];//visit정보 
int dh[]={-1,1,0,0};
int dw[]={0,0,-1,1};
bool isInside(int a, int b){
	return ((a>=1) && (a<=H) && (b>=1) && (b<=W));}

int BFS(){
	int h,w,nh,nw;
	queue<pair<int,int>>q;
	q.push(pair<int,int>(sh,sw));
	
	visit[sh][sw]=0;

	while(!q.empty()){
		h=q.front().first;
		w=q.front().second;
		q.pop();
		if(h==eh && w==ew) return visit[h][w];
		for(int i=0; i<4; i++){
			nh=h+dh[i];
			nw=w+dw[i];
			if(isInside(nh,nw) && map[nh][nw]=='0' && visit[nh][nw]==0){
				visit[nh][nw]=visit[h][w]+1;	
				q.push(pair<int,int>(nh,nw));
			}
		}
	}
	return -1;
}
void InputData(){
	cin >> W >> H;
	cin >> sw >> sh >> ew >> eh;
	for (int i=1; i<=H; i++){
		cin >> &map[i][1];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력

	ans=BFS();//여기서부터 작성

	cout << ans << "\n";//출력
	return 0;
}
