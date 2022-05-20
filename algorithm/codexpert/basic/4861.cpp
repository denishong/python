#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보

int mapCheck[MAXN][MAXN];
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};

bool isInside(int a, int b){
    return (a>=1 && a<=H) && (b>=1 && b<=W);
}
void Print_mapCheck(){
    cout << endl;
    for( int i=1; i <= H; i++){
        for( int j=1; j <= W; j++){
            cout << mapCheck[i][j];
        }
        cout << endl;
    }
}

int BFS(){

    int cur_y = sh, cur_x = sw;
    queue<pair<int,int>> q;
    q.push(pair<int, int>(cur_y, cur_x));
    mapCheck[cur_y][cur_x] = 0;

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        if( cur_y == eh && cur_x == ew) {return mapCheck[cur_y][cur_x]; }
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + d[i][0];
            int next_x = cur_x + d[i][1];

            if(isInside(next_y , next_x ) && mapCheck[next_y][next_x] == 0 &&  map[next_y][next_x] != '1'){
                mapCheck[next_y][next_x] = mapCheck[cur_y][cur_x] + 1;
                q.push( pair<int, int>(next_y, next_x) );
            }
        }
    }
    return -1;
}

void InputData(){
    cin >> W >> H;
    cin >> sw >> sh >> ew >> eh;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
}

int main(){
	int ans = 0;
    InputData();

    ans = BFS();
    cout << ans << endl;
    return 0;
}
