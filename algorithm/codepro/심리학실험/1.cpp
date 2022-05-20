#include <iostream>
using namespace std;
#define MAXN ((int)1e5+10)
#define ABS(x) (((x)<0) ? -(x) : (x))
int N;
int A[MAXN];
void InputData(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}
void Solve(void){
    int sum=(int)2e9+1;
    int sol1, sol2;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N; j++){
            if(sum > ABS(A[i]+A[j])){
                sum=ABS(A[i]+A[j]);
                sol1=i;
                sol2=j;
            }
        }
    }
    cout << sol1 << ' ' << sol2 << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
