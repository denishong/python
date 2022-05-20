/*[2110]공유기 설치*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)2e5+10)
int N,C; //집의 개수, 공유기개수 
int X[MAXN];
long long M;

void Solve(){
    int lo, hi, mid;
    long long sum;
    sort(X,X+N);
    lo = 1;
    hi = X[N-1] - X[0];
    int d = 0;
    int ans = 0;
    while(lo <= hi){
        mid=(lo+hi)/2; 
        int start = X[0];
        int cnt = 1;
        for(int i=1; i<N; i++){
            d = X[i] - start;
            if(mid <= d){
                ++cnt;
                start = X[i];
            }
       cout << "i: " << i << " X[i] : " << X[i] << " lo:" <<  lo  << " hi : " << hi  <<  " mid: " << mid <<  " start: " << start << " cnt :" << cnt << " d:" << d  << endl;
         }
        if( cnt >= C){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }

        }
    cout << ans << endl;
}
void InputData(){
    cin >> N >> C;
    for(int i =0; i<N; i++){
        cin >> X[i];
    }
}

int main(){
    InputData();
    Solve();
    return 0;
}
/*[2110]공유기 설치*/
