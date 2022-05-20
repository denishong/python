/*baekjoon 2573 빙산*/
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define MAXN ((int) 3e2) 

int N,M; /*N: colum M: row*/
int map[MAXN+10][MAXN+10];
bool visited[MAXN+10][MAXN+10];
int dy[]={-1, 1, 0, 0};
int dx[]={0, 0, 1, -1};
struct Q{
	int y,x;
};
bool inRange(int y, int x){
    return( (y>=1) && (y<N-1) && (x >=1) && (x<=M-1));}

void DFS(int y,int x){
    int nx,ny;
    visited[y][x]=true;
    for(int i=0; i<4; i++){
        ny=y+dy[i];
        nx=x+dx[i];
        if(inRange(ny,nx) && map[ny][nx] && !visited[ny][nx])
            DFS(ny,nx);
    }
}
void BFS(int y, int x){
    queue<Q>q;
    q.push({y,x});

    while(!q.empty()){
        Q cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if(inRange(ny, nx) && map[ny][nx] && !visited[ny][nx]){
                q.push({ny,nx});
                visited[ny][nx] =true;
            }
        }	
    }
}
void remap(){
    int copy[MAXN][MAXN];
    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            copy[y][x]=map[y][x];

    for(int y=1; y<N-1; y++){
        for(int x=1; x<M-1; x++){
            if(copy[y][x]){
                int cnt=0;
                for(int i=0; i<4; i++){
                    int ny=y+dy[i];
                    int nx=x+dx[i];
                    if(copy[ny][nx]==0)
                        cnt++;
                }
                map[y][x]=max(copy[y][x]-cnt,0);
            }
        }
    }
}
void Solve(){
    int year=0;
    while(1){
        memset(visited,false,sizeof(visited));
        bool result=false;
        int cnt=0;
        for(int i=1; i<N-1; i++){
            for(int j=1; j<M-1; j++){
                if(map[i][j] && visited[i][j]==false){
                    cnt++;
                    if(cnt==2){
                        result=true;
                        break;
                    }
                    //DFS(i,j);
                    BFS(i,j);
                }
            }
        }
        if(result)
           break;
        if(cnt==0){
            year=0;
            break;
        }
        remap();
        year++;
    }
    cout << year << endl;
}
void InputData(){
    cin >> N >> M;
    for( int i=0; i<N; i++){
        for( int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*baekjoon 2573 빙산*/
