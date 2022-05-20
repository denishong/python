#include <iostream>
#include <queue>
using namespace std;
#define MAXN (50)
int N, M;//세로길이, 가로길이
int map[MAXN+10][MAXN+10];//지도정보
int visited[MAXN+10][MAXN+10][5];//지도정보([세로][가로][방향])
int sh, sw, sd;//시작 세로, 가로, 방향
struct Q{
	int h,w,d;
};
queue<Q>q;
int count;
inline void push(int h, int w, int d, int t){
	if(visited[h][w][d]==1) return; //이미 해본 경험 
	visited[h][w][d]=1;
	q.push({h,w,d});
}
int BFS(){
	int dh[]={-1,0,1,0};//북 동 남 서
	int dw[]={0,1,0,-1};
	bool t = false;
	int nd,nh,nw;
	//1.초기화 
	count=0;
	q={};
	//2.큐에 초기값 저장 
	q.push({sh,sw,sd});	
	//3.반복문 
	while(!q.empty()){
		Q cur=q.front();
		q.pop();
		if(map[cur.h][cur.w]==0){
			map[cur.h][cur.w]=2;
			count++;
		}
		//1.왼쪽방향으로 돌려서 
		for(int i=0; i<4; i++){
			nd=(cur.d-i+3)%4;
			nh=cur.h+dh[nd];
			nw=cur.w+dw[nd];
			if((nh<0) || (nh>=N) || (nw<0) || (nw>=M) || map[nh][nw]!=0) continue;
			q.push({nh,nw,nd});
			break;
		}

		if(q.empty()){
			nd=cur.d;
			nh=cur.h+dh[(nd+2)%4];
			nw=cur.w+dw[(nd+2)%4];
			if((nh<0) || (nh>=N) || (nw<0) || (nw>=M) || map[nh][nw]==1) break;
			q.push({nh,nw,nd});
		}
	}
	return count;
}
void InputData(){
	cin >> N >> M;
	cin >> sh >> sw >> sd;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
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
