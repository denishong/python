#include <iostream>
#include <queue>
using namespace std;

int N; // 세로크기
int M; // 가로크기
int map[50 + 10][50 + 10]; // 사진 데이터

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
queue <pair <pair<int,int>,int>> q;
void InputData(void){
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> map[i][j];
            map[i][j]++;
        }
    }
}

int FloodFill(int y, int x){
    if(map[y][x]!=2) return 0;
    map[y][x]=3;
    int cnt=0;
    for(int i=0; i<4; i++){
        cnt += FloodFill(y+dy[i], x+dx[i]);
    }
    if(cnt<4){
        q.push(make_pair(make_pair(y,x),0));
        map[y][x]=3;
    }
    return 1;
}
void SaveStart(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if(map[i][j]==2){
                FloodFill(i,j);
                cout << "i,j" << i << ',' << j << endl;
                return;
            }
        }
    }
}
int Solve(){
    int x,y,t,ny,nx;

    SaveStart();
    while(!q.empty()){
        y=q.front().first.first;
        x=q.front().first.second;
        t=q.front().second;
        q.pop();
		
        for(int i=0; i<4; i++){
            ny=y+dy[i];
            nx=x+dx[i];
            if(map[ny][nx]==2) return q.front().second;
            if(map[ny][nx]!=1) continue;
            q.push(make_pair(make_pair(ny,nx),t+1));
            map[ny][nx]=3;
        }
    }
    return -1;
}
int main(void){
    InputData();
    cout << Solve() << endl;
    return 0;
}
