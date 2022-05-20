#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)3e6)
#define MAXD ((int)3e3)
#define MAXK ((int)3e3)
int N, D, K, C;//접시수, 종류수, 연속해서 먹는 접시의 수, 쿠폰번호
int A[MAXN + MAXK];
int P[MAXN + MAXK];
int Find(int s){
    int cnt=0;
    for(int i=0; i<K; i++){
        P[i]=A[s+i];
    }
    sort(P,P+K);
    cnt=1;
    for(int i=0; i<K-1; i++){
       if(P[i]==P[i+1]) continue;
        cnt++; 
    }
    for(int i=0; i<=K; i++){
        if(P[i]==C){
        //cout << "i,C,P[i]: " << i << ' ' << C << ' ' << P[i] << endl;
         break;
        }
        if(i==K) cnt++;
    }
    //cout << "cnt : " << cnt << endl;
    return cnt;
}
int Solve(){
    int max=0,sol;
    for(int i=0; i<=N-K; i++){
        sol=Find(i);
        if(max<sol) max=sol;
    }
    return max;
}
void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;

    InputData();// 입력받는 부분

    ans=Solve();// 여기서부터 작성

    cout << ans << "\n";// 출력하는 부분
    return 0;
}
