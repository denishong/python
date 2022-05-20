/*[2512]예산*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e4+10)
int K,N;
int A[MAXN];
long long M;

void InputData(){
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> A[i];
    }
    cin >> M;
}
void Solve(){
    int lo, hi, mid;
    int result;
    long long sum;
    sort(A,A+N);
    lo = 0;
    hi = A[N-1];
    while(lo <= hi){
        long long sum=0;
        mid=(lo+hi)/2; 
        for(int i=0; i<N; i++){
            sum += min(A[i], mid);
            cout << "i: " << i << " A[i] : " << A[i] << " lo:" <<  lo  << " hi : " << hi  <<  " mid: " << mid <<  " sum: " << sum << endl;
        }
        if(sum <=  M){
            lo =mid+1;
            result = mid;
        } else hi = mid-1;
    }
    cout << result << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[2512]예산*/
