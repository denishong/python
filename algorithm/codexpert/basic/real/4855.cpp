/*[4855][실전] 냉장고*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2) 
int N;
struct Data{
    int s, e;
};
struct Data A[MAXN +10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}
bool comp(struct Data a, struct Data b){ return a.s < b.s;}
int Solve(){
    int cnt=1,e;
    sort(A,A+N,comp);
    e = A[0].e;
    for(int i=1; i<N; i++){
        if( e< A[i].s){
            cnt++;
            e=A[i].e; 
        }else if(e > A[i].e){
            e = A[i].e;
        }
    }
    return cnt;
}
int main(){
    InputData();
    int ans = Solve();
    cout << ans << endl;
    return 0;
}
/*[4855][실전] 냉장고*/
