#include <iostream>
#include <algorithm>
using namespace std;

#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];
int paper[MAX+10][100+10];
int sol[MAX * MAX];//각 영역 넓이 저장용
int cnt;
void FillPaper(int sx, int sy, int ex, int ey){
	for(int i=sy; i<ey; i++){
		for(int j=sx; j<ex; j++){
			paper[i][j]=1;
		}
	}
}
bool isInside(int a, int b){
	return ((a>=0) && (a<M) && (b>=0) && (b<N));
}
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
void FloodFill(int y, int x){
	if(!isInside(y,x) || paper[y][x]!=0) return;
	paper[y][x]=2;
	cnt++;
	for(int i=0; i<4; i++){
		FloodFill(y+dy[i],x+dx[i]);	
	}

}
int Solve(){
	int count=0;
	//1. 영역 채우기 	
	for (int i=0; i<K; i++){
		FillPaper(sx[i], sy[i], ex[i] ,ey[i]);
	}
	//2.FloodFill로 영역 면적과 갯수 구하기 
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cnt=0;
			if(paper[i][j]==0){
				FloodFill(i,j);
				sol[count++]=cnt;
			}
		}
	}
	sort(sol, sol+count);
	return count;
}
void InputData(){
	cin >> M >> N >> K;
	for (int i=0; i<K; i++){
		cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
	}
}
void OutputData(int ans){
	cout << ans << "\n";
	for (int i=0; i<ans; i++){
		cout << sol[i] << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	ans=Solve();//여기서부터 작성

	OutputData(ans);//출력하는 부분
	return 0;
}
