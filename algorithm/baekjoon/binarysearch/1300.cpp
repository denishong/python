/*[1300]K번째 수*/
#include <bits/stdc++.h>
using namespace std;
int N,K; 

void InputData(){
    cin >> N >> K;
}
void Solve(){
    int lo, hi, mid;
    lo = 1;
    hi = K;
    while(lo <= hi){
        mid=(lo+hi)/2; 
        int tmp = 0;
        for(int i=1; i<=N; i++){
            tmp += min(mid/i,N);
       //cout << "i: " << i << " lo:" <<  lo  << " hi : " << hi  <<  " mid: " << mid <<  " tmp: " << tmp << endl;
         }
        if( tmp >= K){
            hi  = mid - 1;
        }else{
            lo = mid + 1;
        }

    }
    cout << lo << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[1300]K번째 수*/
