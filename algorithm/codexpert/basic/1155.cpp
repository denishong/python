#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보
int visit[MAXN+10][MAXN+10];//지도정보
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void InputData(){
    cin >> W >> H;
    cin >> sw >> sh >> ew >> eh;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
}
void Solve(int x, int y){
    int nx,ny;
    queue<pair<int,int>>q;
    q.push(pair<int,int>(x,y));
    visit[y][x]=1;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            nx=x+dx[i];
            ny=y+dy[i];
            if(map[ny][nx]=='0' && visit[ny][nx]==0){
                visit[ny][nx]=visit[y][x]+1;
                q.push(pair<int,int>(nx,ny));
            }
        }
    }
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
          cout <<  visit[i][j] << ' ';
        }
        cout << endl;
     }
   // cout << visit[eh][ew]-1 << endl;
}
int main(){
    InputData();
    Solve(sw,sh);
    return 0;
}
