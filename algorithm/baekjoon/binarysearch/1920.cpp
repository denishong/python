/*[1920]수찾기*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e6)
int N;
int A[MAXN +10];
int M;
int X[MAXN+10];

bool BinarySearch(int s, int e, int d){
    int m;
    while(s<=e){
        m=(s+e)/2;
        if(A[m]==d) return 1;
        else if(A[m]>d) e=m-1;
        else s = m+1;
    }
    return 0;
}

void Solve(){
    sort(A,A+N);
    for(int i=0; i<M; i++){
        //printf("%d\n", BinarySearch(0, N-1, X[i]));
        printf("%d\n", binary_search(A, A+N, X[i]));
    }
}

void InputData(){
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> A[i];
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> X[i];
    }
}

int main(){
    InputData();
    Solve();
    return 0;
}
/*[1920]수찾기*/
