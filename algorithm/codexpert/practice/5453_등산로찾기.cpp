#include <iostream>
#include <queue>
using namespace std;

#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
#define INF (50 * 50 * MAXN * MAXN)
struct Q{
	int h;
	int w;
};
void InputData(){
	cin >> N;
	cin >> eh >> ew;
	for (int h=1; h<=N; h++){
		for (int w=1; w<=N; w++){
			cin >> map[h][w];
		}
	}
}
queue<Q>q;
int BFS(){
	int h,w;
	Q cur;
    int dh[] = {-1, 1, 0, 0};
    int dw[] = {0, 0, -1, 1};
    //1.초기화
    for (int h=0; h<=N+1; h++){
        for (int w=0; w<=N+1; w++){
            visited[h][w]=INF;
        }
    }
    //2.시작위치 큐에 저장
    q.push({0,0});
	visited[0][0]=0;
    //3.반복문
    while(!q.empty()){
		cur=q.front();q.pop();
        //h= tmp.h;
        //w= tmp.w;
        for (int i=0; i<4; i++){
            int nh = cur.h+dh[i];
            int nw = cur.w+dw[i];
            if ((nh<0)||(nh>N+1)||(nw<0)||(nw>N+1)) continue;//범위 벗어남
            int power = map[h][w] - map[nh][nw];//현재 격자 높이  - 갈곳 격자 높이
            if (power < 0) power *= power;//음수면 오르막길이므로 제곱
			if(visited[nh][nw] > visited[h][w]+power){
				visited[nh][nw] = visited[h][w]+power;
            	q.push({nh,nw});
            	//q.push(tmp);
			}
        }
    }
    //4.결과
    return visited[eh][ew];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력 받는 부분

	//여기서부터 작성
	ans=BFS();
	cout << ans << "\n";//출력하는 부분
	return 0;
}
