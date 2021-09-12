#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 1e2)
int N,cnt=0;
int mmap[MAXN+10][MAXN+10];
int reMap[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int minval=MAXN, maxval=0;
int dy[]={-1,1,0,0,-1,-1,1,1};
int dx[]={0,0,-1,1,-1,1,-1,1};
bool isInside(int a, int b){
    return ( (a>=1) && (b<=N) && (b>=1) && (b<=N));}

void InputData(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> mmap[i][j];
            if(minval > mmap[i][j]) minval=mmap[i][j];
            if(maxval < mmap[i][j]) maxval=mmap[i][j];
        }
    }
}
void OutputData(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << reMap[i][j] << ' ';
        }
        cout << endl;
    }
}
void remap(int num){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(mmap[i][j] <= num){ 
             reMap[i][j] =0;
            }else{
             reMap[i][j] =1;
            }
        }
    }
}
void BFS(int y, int x ){
    int ny,nx;
    queue <pair<int,int>> q;
    q.push(pair<int,int>(y,x));
    reMap[y][x]=0;
    while(!q.empty()){
        y=q.front().first;
        x=q.front().second;

        q.pop();
        for(int i=0; i<8; i++){
            ny=y+dy[i];
            nx=x+dx[i];
            if(isInside(ny,nx) && reMap[ny][nx]==1){
                q.push(pair<int,int>(ny,nx));
                reMap[ny][nx]=0;
            }
        }
    }
}
void DFS(int y, int x){
    if(reMap[y][x] != 1) return;
    reMap[y][x] = 0;

    for( int i=0; i<8; i++){
        DFS(y+dy[i], x+dx[i]);
    }
}
void Solve(void){
    int maxcnt=0;
	for(int k=0; k<maxval; k++){
        memset(reMap, false, sizeof(reMap));
        remap(k);
        cnt=0;
        for(int i=1; i<=N; i++){
             for(int j=1; j<=N; j++){
                if(reMap[i][j] == 1 ){
                    BFS(i,j);
                    cnt++;
                }
            }
	    }
        if( cnt > maxcnt) maxcnt = cnt;
    }
    cout << "cnt:" << maxcnt << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
