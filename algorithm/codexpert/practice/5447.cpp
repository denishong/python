#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];

int sol[MAX * MAX];//각 영역 넓이 저장용
int map[MAX+10][MAX+10];
int cnt;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
bool isInside(int a, int b){
	return ( a>=0 && a<M && b>=0 && b<N);}

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
void BFS(int y, int x){
	int ny,nx;
	queue<pair<int,int>>q;
	q.push(pair<int,int>(y,x));
	map[y][x]=1;	
	while(!q.empty()){
		y=q.front().first;
		x=q.front().second;
		q.pop();

	for(int i=0; i<4; i++){
		ny=y+dy[i];
		nx=x+dx[i];
		if(isInside(ny,nx) && map[ny][nx]==0){
			map[ny][nx]=1;
			cnt++;
			q.push(pair<int,int>(ny,nx));
		}
	}

	}
}
void FloodFill(int y, int x){
	//1.종료조건 및 표시
	if(!isInside(y,x)) return;//범위 벗어남 
	if(map[y][x]!=0) return;
	map[y][x]=2;
	cnt++;
	//2.확산 
	for(int i=0; i<4; i++){
		FloodFill(y+dy[i], x+dx[i]);
	}
}
void Solve(){
	int count=0;
	for(int i=0; i<K; i++){
		for(int y=sy[i]; y<ey[i]; y++){
			for(int x=sx[i]; x<ex[i]; x++){
				map[y][x]=1;	
			}
		}
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if( map[i][j] ==0){
			cnt=1;
				BFS(i,j);		
				//FloodFill(i,j);
				sol[count++]=cnt;
			}
		}
	}
	cout << count << endl;
	sort(sol,sol+count);
	for(int i=0; i<count; i++)
		cout << sol[i] << ' ';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	Solve();
	//OutputData(ans);//출력하는 부분
	return 0;
}
