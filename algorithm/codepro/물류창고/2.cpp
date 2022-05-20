#include <bits/stdc++.h>
using namespace std;

int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D

#define IMP (100 * 100 + 10)
#define MAXQ (100 * 100 * 100)
#define MAXN ((int) 1e2+10)
int dist[MAXN][MAXN];
int visited[MAXN];
queue<int> q;
int BFS(int s){
    int i, tmp,  max = 0;
    for (i = 1; i <= N; i++) visited[i] = IMP;
    visited[s]=0;
    q.push(s);
    while(!q.empty()){
        tmp = q.front(); 
        q.pop();
        for(i = 1; i <= N; i++){
            if(visited[i] <= (visited[tmp]+dist[tmp][i])) continue; 
            visited[i] = visited[tmp] + dist[tmp][i];
            q.push(i);
        }
    }
    for (i = 1; i <= N; i++){
        if(max < visited[i]) max = visited[i];
    }
    return max;
}
int Solve(){
    int i, j, sol = IMP, ret;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            dist[i][j] = IMP;
        }
    }
    for (i = 0; i < M; i++) dist[A[i]][B[i]] = dist[B[i]][A[i]] = D[i];
    for (i = 0; i < N; i++){
        for(j=0; j<N; j++){
        cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    for(i = 1; i <= N; i++){
        ret = BFS(i);
        if(sol > ret) sol = ret;
    }
    return sol;
}
void InputData(){
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> A[i] >> B[i] >> D[i];
    }
}
int main(){
    InputData();
    cout << Solve() << endl;
    return 0;
}
