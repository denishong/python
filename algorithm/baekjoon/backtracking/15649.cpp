/*[baekjoon][15649]N과M(1)*/
#include <iostream>
#include <vector>
using namespace std;
#define MAXN ((int) 9)
int N,M;
int D[MAXN];
bool visited[MAXN];
vector <int> v;
void DFS( int cnt){
    if(cnt==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++){
        cout << __LINE__ << " visited[" << i << "]" << visited[i] << " cnt : " << cnt << endl;
        if(visited[i]==true) continue;
        visited[i]=true;
        v.push_back(i);
        cout << __LINE__ << " visited[" << i << ']' <<  visited[i] << " cnt : " << cnt << endl;
        DFS(cnt+1);
        visited[i]=false;
        v.pop_back();
    }
}
void Solve(){
    DFS(0);
}
void InputData(){
    cin >> N >> M;
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon][15649]N과M(1)*/
