#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s, e;
};
DATA A[MAXN + 10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}
bool comp(struct DATA A, struct DATA B){
return (A.e< B.e);
}
void Solve(){
    queue<pair<int,int>>q;
    int cnt=1;
    int e;
    sort(A,A+N,comp);

    for (int i=0; i<N; i++){
        if(A[i].e-A[i].s>=2)
            q.push(pair<int,int>(A[i].s, A[i].e));
    }
    e=q.front().second;q.pop();
    while(!q.empty()){
        //cout << q.front().first << ' ' <<  q.front().second<< endl;
        if(e<=q.front().first){
            ++cnt;
            e=q.front().second;
            q.pop();
        }else{
            q.pop();
        }
    }
    cout << cnt<< endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();
    Solve();
    return 0;
} 
