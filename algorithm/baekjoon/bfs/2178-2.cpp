/*baekjoon 2178 미로탐색 BFS*/
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

#define MAXN 100 

int N, M ;// 세로(행) ,가로(열)  
int map[MAXN][MAXN];
int mapCheck[MAXN][MAXN];
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};

bool isInside(int a, int b){
    return (a>=0 && a<N) && (b>=0 && b<M);
}

void BFS(){

    int cur_y = 0, cur_x = 0;
    queue<pair<int,int>> q;
    q.push(pair<int, int>(cur_y, cur_x));
    mapCheck[cur_y][cur_x] = 1;

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + d[i][0];
            int next_x = cur_x + d[i][1];

            if(isInside(next_y , next_x ) && mapCheck[next_y][next_x] == 0 &&  map[next_y][next_x]){
                mapCheck[next_y][next_x] = mapCheck[cur_y][cur_x] + 1;
                q.push( pair<int, int>(next_y, next_x) );
            }
        }
    }

}


void Print_mapCheck(){
    cout << endl;
    for( int i=0; i < N; i++){
        for( int j=0; j < M; j++){
            cout << mapCheck[i][j];
        }
        cout << endl;
    }
}

void Print_map(){
    printf("\n");
    for( int i=0; i < N; i++){
        for( int j=0; j < M; j++){
            printf("%d", map[i][j] );
        }
        printf("\n");
    }
}

void InputData(){
    scanf("%d %d", &N, &M);
    for( int i=0; i < N; i++){
        for( int j=0; j < M; j++){
            scanf("%1d", &map[i][j] );
        }
    }
}

void OutputData(){
    cout << mapCheck[N-1][M-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    InputData();

    BFS();
    OutputData();
    return 0;
}
/*baekjoon 2178 미로탐색 BFS*/
