/*baekjoon 2178 미로탐색 BFS*/
#include <iostream>
#include <queue>
using namespace std;

#define MAXN ((int) 1e2 + 10)
int N, M ;// 세로(행) ,가로(열)  
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int dy[4]= {-1,1,0,0};
int dx[4]= {0,0,1,-1};
struct Q{
    int y,x;
};
bool isInside(int a, int b){
    return (a>=1 && a<=N && b>=1 && b<=M);
}
void BFS(){
	int x=1,y=1,nx,ny;
    queue<Q>q;
    q.push({y, x});
    visited[y][x] = 1;

    while(!q.empty()) {
        Q cur=q.front();
        q.pop();
		if(y==N && x==M) {cout<<visited[y][x];}
        for (int i = 0; i < 4; i++) {
            ny = cur.y + dy[i];
            nx = cur.x + dx[i];

            if(isInside(ny,nx) && visited[ny][nx]==0 &&  map[ny][nx] == '1'){
                visited[ny][nx] = visited[cur.y][cur.x] + 1;
                q.push({ny, nx});
            }
        }
    }
}
void InputData(){
    cin >> N >> M;
    for( int i=1; i <= N; i++){
        cin >> &map[i][1];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    InputData();
    BFS() ;
    return 0;
}
/*baekjoon 2178 미로탐색 BFS*/
