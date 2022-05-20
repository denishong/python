/*[2805]나무자르기*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e6+10)
int N;
int A[MAXN +10];
long long M;

void InputData(){
    cin >> N >> M;
    for(int i =0; i<N; i++){
        cin >> A[i];
    }
}
void Solve(){
    int lo, hi, mid;
    long long sum;
    sort(A,A+N);
    lo = 1;
    hi = A[N-1];
    while(lo <= hi){
        sum=0;
        mid=(lo+hi)/2; 
        for(int i=0; i<N; i++){
            if(A[i] > mid) sum += (A[i] - mid);
            //cout << "i: " << i << " A[i] : " << A[i] << " lo:" <<  lo  << " hi : " << hi  <<  " mid: " << mid <<  " sum: " << sum << endl;
        }
        if(sum >= M) lo=mid+1;
        else hi = mid-1;
    }
    cout << hi << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[2805]나무자르기*/
