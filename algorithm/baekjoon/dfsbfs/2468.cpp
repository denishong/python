/*baekjoon 2468 안전 영역*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2) 

int N,cnt=0,maxval=0,minval=MAXN;
int Map[MAXN+10][MAXN+10];
int reMap[MAXN+10][MAXN+10];

int dy[]={-1, 1, 0, 0};
int dx[]={0, 0, 1, -1};
int nx,ny;
bool inRange(int y, int x){
    return( (y>=1) && (y<=N) && (x >=1) && (x<=N));}

void DFS(int y, int x){
    if(reMap[y][x] != 1) return;
    reMap[y][x] = 0;

    for(int i=0; i<4; i++){
        DFS(y+dy[i], x+dx[i]);
    }
}
void remap(int num){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
        if(Map[i][j] <= num){
            reMap[i][j] = 0;
        }else{
            reMap[i][j] = 1;
        }
        }
    }
}
void Solve(){
    int maxcnt=0;
    for(int k=1; k<100; k++){
    memset(reMap, false, sizeof(reMap));
    remap(k);
    cnt=0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(reMap[i][j] == 1 ){
                DFS(i,j);
                cnt++;
            }
        }
    }
        if( cnt > maxcnt) maxcnt = cnt;
    }
    cout << maxcnt << endl;
}
void InputData(){
    cin >> N;
    for( int i=1; i<=N; i++){
        for( int j=1; j<=N; j++){
            cin >> Map[i][j];
            if(minval > Map[i][j] ) minval= Map[i][j];
            if(maxval < Map[i][j] ) maxval= Map[i][j];
        }
    }
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*baekjoon 2468 안전 영역*/
