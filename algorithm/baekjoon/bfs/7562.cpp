/*[baekjoon]7562 나이트의 이동*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 3e2)
int Map[MAXN+10][MAXN+10];
bool visited[MAXN+10][MAXN+10];
int T;//test case
int N;//Map size
int sy,sx,ey,ex;
int dy[]={2,1,2,1,-2,-1,-2,-1};
int dx[]={1,2,-1,-2,-1,-2,1,2};
bool inRange(int x, int y){
    return ( (x>=0) && (x<N) && (y>=0) && (y<N));
}

void BFS(int y, int x){
    int ny,nx;
    queue <pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x]=true;

    while(!q.empty()){
        y=q.front().first;
        x=q.front().second;
        q.pop();
        if((y==ey) && (x==ex)) break;
        for(int i=0; i<8; i++){
            ny=y+dy[i];
            nx=x+dx[i];
            if(inRange(ny,nx) && !visited[ny][nx]){
                visited[ny][nx]=true;
                Map[ny][nx]=Map[y][x]+1;
                q.push(make_pair(ny,nx));
            }
        }

    }

}
void InputData(){
    cin >> T;
}
void Solve(){
    for(int i=0; i<T; i++){
        cin >> N;
        cin >> sy >> sx >> ey >> ex ;
        BFS(sy,sx);
        cout << Map[ey][ex] << endl;
        memset(Map, false, sizeof(Map));
        memset(visited, false, sizeof(visited));
    }
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon]7562 나이트의 이동*/
