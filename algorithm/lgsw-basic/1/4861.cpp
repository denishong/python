#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보
int visited[MAXN+10][MAXN+10];//방문 지도정보
int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool isInside(int y, int x){
    return( (y>=1) && (y<=H) && (x>=1) && (x<=W));
}

void InputData(){
    cin >> W >> H;
    cin >> sw >> sh >> ew >> eh;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
}
int BFS(){
    int cur_x, cur_y,next_x,next_y;
    queue<pair<int, int>> q;	
    cur_x = sw, cur_y = sh;
    q.push(pair<int,int>(cur_y, cur_x));
    visited[cur_y][cur_x] = 0;
    while(!q.empty()){
       cur_y= q.front().first; 
       cur_x= q.front().second; 
        if( (cur_y==eh) && (cur_x==ew) ) {return visited[cur_y][cur_x];}
       q.pop(); 
        for(int i=0; i<4; i++){
            next_y = cur_y + d[i][0];
            next_x = cur_x + d[i][1];
            if(isInside(next_y,next_x) && visited[next_y][next_x] == 0 && map[next_y][next_x] != '1'){
            visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
            q.push(pair<int,int>(next_y, next_x));
        }

        }
    }

    return -1;
}
int main(){
	int ans = 0;
    InputData();
	ans = BFS();
    cout << ans << endl;
    return 0;
}
