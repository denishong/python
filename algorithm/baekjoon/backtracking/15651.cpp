#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 9)
int N,M;
int D[MAXN+1];
bool visited[MAXN+1];
vector <int> v;
void DFS(int idx, int Cnt){
    if(Cnt==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++){
        visited[i]=true;
        v.push_back(i+1);
        DFS(i,Cnt+1);
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
/*[baekjoon]*/
