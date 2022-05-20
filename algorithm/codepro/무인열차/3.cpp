#include <iostream>
#include <queue>
using namespace std;
#define MAXN ((int) 5e1 +10)
int N;
int M;
int map[MAXN][MAXN];
int Count;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct st
{
    int r, c;
}dat[2][50*50];

void BFS(int y, int x, int p){
    int nx, ny;
    queue<pair<int,int>> q;

    q.push(pair<int,int>(y,x));
    dat[p][Count].r =  x;
    dat[p][Count].c =  y;
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if (map[ny][nx] == 0) continue;
            map[ny][nx] = 0;
            Count++;
            q.push(pair<int,int>(ny,nx));
            dat[p][Count].r = nx;
            dat[p][Count].c = ny;
        }
    }
}
void Solve(void){
    int ans = 0x7FFFFFFF;
    int point = 0;
    int cnt[2];

    for (int i = 1; i <= N; i++){
       for (int j = 1; j <= M; j++){
            if (map[i][j] == 1){
                Count = 1;
                cout << "Count : " << Count << "point : " << point <<  endl;
                BFS(i, j, point);
                cnt[point] = Count;
                point++;
            }
        }
    }
    for (int i = 1; i <= cnt[0]; i++){
        for (int j = 1; j <= cnt[1]; j++){
            int temp = abs(dat[0][i].r - dat[1][j].r) + abs(dat[0][i].c - dat[1][j].c);
            cout << "temp : " << temp << endl;
            if (temp < ans) ans = temp;
        }
    }
    cout << ans - 1 <<endl;
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
    InputData();
    Solve();
    return 0;
}
