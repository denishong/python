#include <iostream>
using namespace std;
#define MAXW (20)
int N;//도로의 개수
int W;//사건의 개수
struct POS{
	int r, c;//세로, 가로
};
POS pos[MAXW+10];//사건 좌표
#define INF (1<<30)
int sol;//최소 이동 거리
int CalDist(int a, int b){
    return abs(pos[a].r - pos[b].r) + abs(pos[a].c - pos[b].c);
}
void DFS(int w, int p1, int p2, int movecnt){
	cout << "sol,movecnt:" << sol << ' ' << movecnt << endl;
    if (sol <= movecnt) return;//가지치기
    if (w >= W){//종료조건
        sol = movecnt;
        return;
    }
 
    DFS(w+1, w, p2, movecnt+CalDist(p1, w));//p1이 w 사건 처리 경우
    DFS(w+1, p1, w, movecnt+CalDist(p2, w));//p2가 w 사건 처리 경우
}
int Solve(){
    sol = INF;//최솟값 구하므로 최댓값으로 초기화
    pos[W].r=1; pos[W].c=1;//경찰차1 초기 좌표
    pos[W+1].r=N; pos[W+1].c=N;//경찰차2 초기 좌표
    DFS(0, W, W+1, 0);//사건번호, 경찰차1, 경찰차2, 누적이동거리
    return sol;
}
void InputData() {
	cin >> N;
	cin >> W;
	for (int i=0; i<W; i++){
		cin >> pos[i].r >> pos[i].c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	ans=Solve();
	cout << ans << "\n";//출력하는 부분
	return 0;
}
