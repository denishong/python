#include <iostream>
using namespace std;
#define MAXN ((int)1e6+10)
int A[MAXN];
void InputData(void){
    for(int i=0; i<5; i++){
        cin >> A[i];
    }
}
void Solve(void){
    int sum=0;
    for(int i=0; i<5; i++){
        if( A[i] < 40) A[i] = 40;
        sum += A[i];
    }
    cout << sum/5 << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
