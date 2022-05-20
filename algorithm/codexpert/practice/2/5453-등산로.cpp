#include <iostream>
#include <queue>
using namespace std;

#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
#define INF (MAXN*MAXN+MAXN+MAXN)
struct Q{
	int h,w;
};
int BFS(){
	int dh[]={-1,1,0,0};
	int dw[]={0,0,-1,1};
	queue<Q>q;
	//1.큐 초기화 
	for (int h=1; h<=N; h++){
		for (int w=1; w<=N; w++){
			map[h][w]=INF;
		}
	}
	q={};
	//2.초기값 큐에 저장 
	q.push({0,0});
	visited[0][0]=0;
	//3.반복문 
	while(!q.empty()){
		Q cur=q.front();q.pop();
		for(int i=0; i<4; i++){
			int nh=cur.h+dh[i];
			int nw=cur.w+dw[i];
			if( (nh<0) || (nh>=N) || (nw<0) || (nw>=N) ) continue;
			int power = map[cur.h][cur.w]-map[nh][nw];
			if(power < 0) power *=power; //오르막이므로 제곱해줘야한다.
			if(visited[nh][nw] > visited[cur.h][cur.w]){
				visited[nh][nw] = visited[cur.h][cur.w] + power;
				q.push({nh,nw});
			}
		}
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
