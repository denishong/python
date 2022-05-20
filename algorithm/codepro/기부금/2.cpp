#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e6+10)
int N;
long long M;
long long A[MAXN];
void InputData(void){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}
void Solve(void){
    long long s,e,sum;
    int mid,max=0;

    for(int i=0; i<N; i++){
        if(A[i] > max) max=A[i];
    }
    s = 1;
    e = max;

    while( s<=e ){
        sum = 0;
        mid = (s + e)/2;
        for(int i=0; i<N; i++){
            if( A[i] > mid) sum += (long long) (A[i] - mid);
        }
        if( sum >= M) s = mid + 1;
        else e = mid -1;
    }
    cout << e << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
