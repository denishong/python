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
    int minsum=(int)2e9+1,sum;
    int sol1, sol2;
    int i=0, j=N-1;
    while(i<j){
        sum = ABS(A[i]+A[j]);
        if(minsum > ABS(sum) ){
            minsum=ABS(sum);
            sol1=i; sol2=j;
        }
    if(sum < 0) i++;
    else if(sum > 0) j--;
    else break;
    }
    cout << sol1 << ' ' << sol2 << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
