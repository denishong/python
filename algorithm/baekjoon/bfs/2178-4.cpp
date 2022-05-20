/*baekjoon 2178 미로탐색 BFS*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 1e2 + 10)
int N, M ;// 세로(행) ,가로(열)  
char mmap[MAXN][MAXN];
int mapCheck[MAXN][MAXN];
int dy[4]= {-1,1,0,0};
int dx[4]= {0,0,1,-1};

bool isInside(int a, int b){
    return (a>=1 && a<=N) && (b>=1 && b<=M);
}
int BFS(){
	int x=1,y=1,nx,ny;
    queue<pair<int,int>> q;
    q.push(pair<int, int>(y, x));
    mapCheck[y][x] = 1;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
		if(y==N && x==M) {return mapCheck[y][x];}
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if(isInside(ny , nx ) && mapCheck[ny][nx] == 0 &&  mmap[ny][nx] == '1'){
                mapCheck[ny][nx] = mapCheck[y][x] + 1;
                q.push( pair<int, int>(ny, nx) );
            }
        }
    }
    return 1;

}
void InputData(){
    cin >> N >> M;
    for( int i=1; i <= N; i++){
        cin >> &mmap[i][1];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    InputData();
    cout << BFS() << endl;
    return 0;
}
/*baekjoon 2178 미로탐색 BFS*/
