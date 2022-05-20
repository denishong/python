#include <iostream>
using namespace std;

int N; // 세로크기
int M; // 가로크기
int map[50 + 10][50 + 10]; // 사진 데이터
int cnt;
struct D{
	int y,x;
};
struct D d[2][50*50];
int dy[]={-1,1,0,0};//상,하,좌,우
int dx[]={0,0,-1,1};
void FloodFill(int y, int x, int p){
	if(map[y][x]!=1) return;
	cout<<y<<' '<< x<<endl;
	map[y][x]=0;
	d[p][cnt].y=y;
	d[p][cnt].x=x;
	cnt++;
	for(int i=0; i<4; i++){
		FloodFill(y+dy[i], x+dx[i], p);
	}
}
int Solve(){
	int a[2];
	int sol=0x7fffffff,min=0,point=0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cnt=0;
			if( map[i][j]==1){
				FloodFill(i,j,point);
				a[point]=cnt;
				point++;
			}
		}
	}
	for (int i = 0; i < a[0]; i++){
		for (int j = 0; j < a[1]; j++){
			min=abs(d[0][i].x-d[1][j].x) + abs(d[0][i].y-d[1][j].y);
			if(sol>min) sol=min;
		}
	}
	return sol-1;
}
void InputData(void){
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> map[i][j];
		}
	}
 
}
int main(void){
	InputData();	//입력 함수
	cout << Solve() << endl;//출력
    return 0;
}
