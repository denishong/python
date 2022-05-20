#include <iostream>
#include <queue>
using namespace std;

int N; // 세로크기
int M; // 가로크기
int map[50 + 10][50 + 10]; // 사진 데이터
struct cord{
	int y,x;
};
struct cord d[2][50*50];
int cnt;
int count[2];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
bool isInside(int a, int b){
	return ((a>=1) && (b>=1) && (a<=N) && (b<=M)); 
}
void InputData(void){
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> map[i][j];
		}
	}
}
void BFS(int y,int x, int p){
	int nx,ny;
	queue<pair<int,int>>q;
	q.push(pair<int,int>(y,x));
	d[p][cnt].y=y;
	d[p][cnt].x=x;
	map[y][x]=0;
	
	while(!q.empty()){
		y=q.front().first;
		x=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			ny=y+dy[i];
			nx=x+dx[i];
			if(isInside(ny,nx) && map[ny][nx]==1){
				cout << "map[ny][nx]:" << ny << ' ' << nx << endl;
				map[ny][nx]=0;
				cnt++;
				q.push(pair<int,int>(ny,nx));
				d[p][cnt].y=ny;
				d[p][cnt].x=nx;
			}
		}
	}
}
void Solve(){
	int ans=100,point=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cnt=1;
			if(map[i][j]==1){
                BFS(i,j,point);
			    cout << " i,j : " << i << ' ' << j << endl;
			    count[point]=cnt;
			    point++;
            }
		}
	}
	for(int i=0; i<count[0]; i++){
		for(int j=0; j<count[1]; j++){
			if(ans > (abs(d[0][i].x-d[1][j].x) + abs(d[0][i].y-d[1][j].y) ))
				 ans =(abs(d[0][i].x-d[1][j].x) + abs(d[0][i].y-d[1][j].y));
		}
	}
	cout << ans << endl;//출력
}
int main(void){
	InputData();
	Solve();	
	return 0;
}
