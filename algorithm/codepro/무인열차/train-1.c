#include <stdio.h>
 
int N; // 세로크기
int M; // 가로크기
int map[50 + 10][50 + 10]; // 지도 데이터

void InputData(void)
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

#define INF (1<<30)
int visited[50 + 10][50 +10];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
struct POS{
	int r, c;
};

struct POS data[2][50*50];
int datacnt[2];

int ABS(int x) {return (x<0) ? -x:x;}
int CALDIST(int a, int b){
	return (ABS(data[0][a].r - data[1][b].r) + ABS( data[0][a].c - data[1][b].c ));
}

void MakePoint(){
	int idx = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <=M; j++){
int Solve(){
	//L1동과 L2동에 포함된 격자들 좌표 저장
	MakePoint();
	//2.최단 거리 구하기
	return CalPoint();
}

int main(void)
{
	int ans = -1;
	InputData();	//입력 함수
	
	// 코드를 작성 하세요
	ans = Solve();

	printf("%d\n", ans);//출력 
    return 0;
}
