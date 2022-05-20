/*baekjoon 1260 DFS,BFS*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e3) 

int N, M, V;//정점수,간선수,시작점 
int mat[MAXN+10][MAXN+10];
bool visited[MAXN+10];

void init(){
    //for ( int i =0; i <= MAXN; i++) { visited[i] = 0;}
    memset(visited, 0, sizeof(visited));
}
void DFS(int st){
    visited[st] = true;
    cout << st << " ";
    for (int i = 1; i <= N; i++) {
        if (mat[st][i] == 1 && visited[i] == false)
            DFS(i);
    }
}

void BFS(int st){
    queue<int> q;
    visited[st] = true;
    q.push(st);

    while(!q.empty()) {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (mat[temp][i] == 1 && visited[i] == false){
                visited[i] = true;
                q.push(i);
            }
        }
    }

}
void InputData(){
    cin >> N >> M >> V;
    for( int i=0; i < M; i++){
        int x,y;
        cin >> x >> y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
}
int main(){
    InputData();
    DFS(V);
    init();
    cout << endl;
    BFS(V);
    return 0;
}
/*baekjoon 1260 DFS,BFS*/
