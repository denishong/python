/*baekjoon 1012 유기농 배추 */
#include <iostream>
#include <queue>
using namespace std;
#define max 50

int t;// test case
int m,n, k;//가로, 세로 , 배추 수 
int map[max][max];
int cnt;
int cur_y, cur_x;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

bool isInside(int a, int b){
    return (a>=0 && a<m) && (b>=0 && b<n);
}
void BFS(int y, int x ){
    int nx,ny;
    queue<pair<int,int>> q;
    q.push(pair<int, int>(y, x));
    map[y][x] = 2;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

        if(isInside(ny, nx) && map[ny][nx]==1){
            q.push(pair<int,int>(ny, nx));
            map[ny][nx]=2;
        }
        }
    }
}
void Solve(){
    cnt = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
        if(map[i][j] == 1 ){
            BFS(i, j);
            cnt++;
        }
        }
    }
    cout << cnt << endl;
}
void Initmap(){
    for( int i=0; i < m; i++){
        for( int j=0; j < n; j++){
            map[i][j] = 0;
        }
    }
}

int main(){
    int x,y;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for( int l=0; l < t; l++ ) {
        cin >> m >> n >> k;
        for( int i=0; i < k; i++){
            cin >> y >> x;
            map[y][x] = 1;
        }
        Solve();
        Initmap();
    }
    return 0;
}
/*baekjoon 1012 유기농 배추 */
