/*baekjoon 4963 섬의개수*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 50
int w,h,cnt;
int Map[MAXN+10][MAXN+10];
int dy[] = {-1,1,0,0,-1,-1,1,1};
int dx[] = {0,0,-1,1,-1,1,-1,1};

void DFS(int y, int x){
    if(Map[y][x] != 1) return;
        Map[y][x] = 0;
    for(int i=0; i<8; i++){
        DFS(y+dy[i], x+dx[i]);
    }

}
void Solve(){
    cnt=0;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if( Map[i][j]==1){
                DFS(i,j);
                cnt++;
            }
        }
     }
    cout << cnt << endl;
}
void InputData(){
    while(1){
        cin >> w >> h;
        if(w==0 && h==0) break;
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> Map[i][j];
            }
         }
     Solve();
    }
}
int main(){
    InputData();

    return 0;
}
/*baekjoon 4963 섬의개수*/
