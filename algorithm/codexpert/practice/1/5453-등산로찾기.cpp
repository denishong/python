#include <iostream>
#include <queue>
using namespace std;

#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
#define INF (50*50*MAXN*MAXN)
struct Q{
	int h,w;
};
queue<Q>q;
void push(int h, int w, int t){
	if(visited[h][w] <= t) return;
	visited[h][w]=t;
	q.push({h,w});
}
int BFS(){
	int dh[]={-1,1,0,0};
	int dw[]={0,0,-1,1};
	//1.queue초기화 
	q={};
	for(int h=0; h<=N+1; h++){
		for(int w=0; w<=N+1; w++){
			visited[h][w]=INF;
		}
	}

	//2.시작위치 큐에 저장 
	push(0,0,0);
	//3.반복문 
	while(!q.empty()){
	Q cur=q.front();
	q.pop();
		for(int i=0; i<4; i++){
			int nh=cur.h+dh[i];
			int nw=cur.w+dw[i];
			if((nh<0) || (nh>N+1) || (nw<0) ||(nw>N+1)) continue;//범위 벗어남 
			int power=map[cur.h][cur.w]-map[nh][nw]; //현재 격자높이 - 갈곳 격자 높이 
			if(power<0) power*=power; //음수이면 오르막길이므로 제곱 
			push(nh,nw,visited[cur.h][cur.w]+power);
		}

	}
		for(int h=0; h<=N+1; h++){
			for(int w=0; w<=N+1; w++){
				cout << visited[h][w] << ' ';
		}
		cout << endl;
	}

	//4.실패 
	return visited[eh][ew];
}
void InputData(){
	cin >> N;
	cin >> eh >> ew;
	for (int h=1; h<=N; h++){
		for (int w=1; w<=N; w++){
			cin >> map[h][w];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력 받는 부분

	ans=BFS();//여기서부터 작성

	cout << ans << "\n";//출력하는 부분
	return 0;
}
