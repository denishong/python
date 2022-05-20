#include <iostream>
#include <queue>
using namespace std;

int N; // 세로크기
int M; // 가로크기
int map[50 + 10][50 + 10]; // 사진 데이터
struct D{
	int y,x;
};
struct D d[2][50*50];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int cnt;
void InputData(void){
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }
}

void FloodFill(int y, int x,int p){
    if(map[y][x]!=1) return;
    map[y][x]=0;
	d[p][cnt].y=y;
	d[p][cnt].x=x;
	cnt++;
    for(int i=0; i<4; i++){
        FloodFill(y+dy[i], x+dx[i],p);
    }
}
int Solve(){
    int p=0,a[2],max,sol=0x7fffffff;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
			cnt=0;
            if( map[i][j]==1){
				FloodFill(i,j,p);
				a[p]=cnt;
				p++;
			}
        }
    }
	for(int i=0; i<a[0]; i++){
		for(int j=0; j<a[1]; j++){
			max=(abs(d[0][i].x-d[1][j].x) + abs(d[0][i].y-d[1][j].y));
			if(sol>max) sol=max;
		}
	}
	return sol-1;
}
int main(void){
    InputData();
    cout << Solve() << endl;
    return 0;
}
