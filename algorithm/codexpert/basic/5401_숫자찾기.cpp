/*[1920]수찾기*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e6)
int N;
int A[MAXN +10];
int M;
int X[MAXN+10];

void InputData(){
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> A[i];
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> X[i];
    }
}
int BinarySearch(int s, int e, int d){
    int m;
    while(s<=e){
        m=(s+e)/2;
        if(A[m]==d) return m;
        else if(A[m]>d) e=m-1;
        else s = m+1;
    }
    return 0;
}
void Solve(){
    sort(A,A+N);
    for(int i=0; i<M; i++){
        printf("%d\n", BinarySearch(1, N, X[i]));
    }
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[1920]수찾기*/
