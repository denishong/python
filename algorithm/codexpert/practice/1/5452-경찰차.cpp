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
int sol;
int CalcDist(int a, int b){
	return ( abs(pos[a].r-pos[b].r) + abs(pos[a].c-pos[b].c));
}
void DFS(int w, int p1, int p2, int movecnt){
	if(sol<movecnt) return;//최단 경로를 찾아야 하므로 movecnt가 더 크면 해볼 필요없다 
	if(w>=W) {
		sol=movecnt;
		return;
	}
	DFS(w+1, w, p2, movecnt+CalcDist(p1,w));//p1이 w사건을 처리한 경우 
	DFS(w+1, p1, w, movecnt+CalcDist(p2,w));//p2가 w사건을 처리한 경우 
}
int Solve(){
	sol=INF;
	pos[W].r=1;pos[W].c=1;
	pos[W+1].r=N;pos[W+1].c=N;
	DFS(0,W,W+1,0); //인덱스,경찰차1,경찰차2,거리 
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
	ans=Solve();//여기서부터 작성
	cout << ans << "\n";//출력하는 부분
	return 0;
}
