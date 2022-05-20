#include <iostream>
using namespace std;
#define MAXN ((int) 1e6+10)
int N,T;
int P[MAXN], S[MAXN];
long long stack[100000 + 10];

void InputData(void){
    cin >> N >> T;
    for(int i=0; i<N; i++){
        cin >> P[i] >> S[i];
    }
}
void Solve(void){
    int i, sp =0;
    long long pos;

    for(i=0; i<N; i++){
        pos = P[i] + (long long)T * S[i];
        for( ; (sp > 0) && (stack[sp] >= pos); sp--);
        stack[++sp] = pos;
    }
    cout << sp;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
