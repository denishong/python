/*
마을의 위성사진을 본철수는 평지와 호수로 나뉘어져 있다는 것을 알았다.
이 사진을 통해 가장 큰 호수의 크기를 파악하려고한다.
상하좌우대각선으로 연결되어 있으면 하나의 호수로 간주한다면 철수의 마을에 있는
가장 큰 호수의 크기를 파악할 수 있는 프로그램을 작성하자.
[입력설명]
첫째줄에는마을의 크기 W,H가 공백으로 구분되어 주어진다.
둘째 줄에는 W개씩 H줄만큼 마을 정보가 공백 없이주어진다.
(0은 평지 1은 호수임)
6 5
001000
100110
010001
001001
110000

*/
#include <iostream>
#include <queue>
using namespace std;
#define MAXN (1000)
int W,H;
char map[MAXN+10][MAXN+10];
int dy[8]={-1,1,0,0,-1,-1,1,1};
int dx[8]={0,0,-1,1,-1,1,-1,1};
int cnt=0;
void InputData(){
	cin >>W >>  H;
	for (int i=1; i<=H; i++){
        cin >> &map[i][1];
	}
}
int BFS(int y, int x){
    int ny,nx;
    queue<pair<int,int>>q;
    q.push(pair<int,int>(y,x));
    cout << "y,x:" << y << ' ' << x << endl;
    map[y][x]='0';
    while(!q.empty()){
        y=q.front().first;
        x=q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            ny=y+dy[i];
            nx=x+dx[i];
            if(map[ny][nx]=='1'){
               cnt++;
               map[ny][nx]='0';
               q.push(pair<int,int>(ny,nx));
            }
        }
    }
    return cnt;
}
void Solve(){
    int ans=0,max=0,ret;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(map[i][j]=='1'){
             cnt=1;
             ret=BFS(i,j);
             if(ret>max) max=ret;
            }
        }
    }
    cout << max << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
