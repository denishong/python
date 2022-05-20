/*[1654]랜선자르기*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e4+10)
int K,N;
int A[MAXN];
long long M;

void InputData(){
    cin >> K >> N;
    for(int i =0; i<K; i++){
        cin >> A[i];
    }
}
void Solve(){
    int lo, hi, mid;
    long long sum;
    sort(A,A+K);
    lo = 0;
    hi = A[K-1];
    while(lo <= hi){
        sum=0;
        mid=(lo+hi)/2; 
        for(int i=0; i<K; i++){
            sum += A[i]/mid;
            //cout << "i: " << i << " A[i] : " << A[i] << " lo:" <<  lo  << " hi : " << hi  <<  " mid: " << mid <<  " sum: " << sum << endl;
        }
        if(sum >= N) lo=mid+1;
        else hi = mid-1;
    }
    cout << hi << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[1654]랜선자르기*/
