#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e3)
int N,M;
int Map[MAXN+10][MAXN+10];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
void InputData(){
    int u,v;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        Map[u][v] = 1;
        Map[v][u] = 1;
    }
}
void DFS(int y, int x){
    if( Map[y][x] == 0) return;
        Map[y][x] = 0;
        Map[x][y] = 0;

    for(int i=0; i<4; i++){
       DFS(y+dy[i], x+dx[i]); 
	}
}
void Solve(){
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(Map[i][j]==1){
                DFS(i,j);
                cnt++;
             }
         }
     }
    cout << cnt << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
