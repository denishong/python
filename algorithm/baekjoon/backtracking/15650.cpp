/*[baekjoon][15650]N과M(2)*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 9)
int N,M;
int D[MAXN];
bool visited[MAXN];
vector <int> v;
void DFS(int idx, int cnt){
    if(cnt==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=idx; i<N; i++){
        if(visited[i]==true) continue;
        visited[i]=true;
        v.push_back(i+1);
        DFS(i,cnt+1);
        visited[i]=false;
        v.pop_back();
    }
}
void Solve(){
    DFS(0,0);
}
void InputData(){
    cin >> N >> M;
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon][15650]N과M(2)*/
