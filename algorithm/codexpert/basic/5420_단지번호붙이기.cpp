#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN (25)
int N;
char map[MAXN+10][MAXN+10];//지도정보
int visit[MAXN+10][MAXN+10];//visit정보 
int B[MAXN+10];//단지 수 저장용 
int cnt;
int dh[]={-1,1,0,0};
int dw[]={0,0,-1,1};
bool isInside(int a, int b){
	return ((a>=1) && (a<=N) && (b>=1) && (b<=N));}

int BFS(int h, int w){
	int nh,nw;
	queue<pair<int,int>>q;
	q.push(pair<int,int>(h,w));
	map[h][w]='0';	
	while(!q.empty()){
		h=q.front().first;
		w=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			nh=h+dh[i];
			nw=w+dw[i];
			if(isInside(nh,nw) && map[nh][nw]=='1' ){
				map[nh][nw]='0';	
				q.push(pair<int,int>(nh,nw));
				cnt++;
			}
		}
	}
	return -1;
}
void DFS(int h, int w){
	if(map[h][w]=='0') return;
	if(isInside(h,w)==0) return;
	cnt++;
	map[h][w]='0';
	for(int i=0; i<4; i++){
		DFS(h+dh[i], w+dw[i]);
	}
}
void Solve(){
	int count=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cnt=0;
			if(map[i][j]=='1'){
				//BFS(i,j);
				DFS(i,j);
				B[count++]=cnt;
			}
		}
	}
	sort(B,B+count);
	cout << count << endl;
	for(int i=0; i<count; i++)
		cout <<	B[i] << endl;

}
void InputData(){
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> &map[i][1];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	Solve();//여기서부터 작성

	return 0;
}
