#include <iostream>
using namespace std;
#define MAXN ((int) 1e6)

int N, M, V;//정점수,간선수,시작점
int map[MAXN+10][MAXN+10];
bool visited[MAXN+10];//방문표시용 배열

void DFS(int n){
    visited[n] = true;
    cout << n << ' ';
    for (int i = 1; i <= N; i++) {
        if (map[n][i] == 1 && visited[i] == false){
            DFS(i);
                }
    }
}

void InputData(){
    cin >> N >> M >> V;
    for( int i=0; i < M; i++){
        int x,y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
}
int main(){
    InputData();
    DFS(V);
    return 0;
}
