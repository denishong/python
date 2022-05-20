#include <iostream>
#include <stack>
using namespace std;
#define MAXN ((int) 1e6+10)
int N,T;
int P[MAXN], S[MAXN];
stack<long long> s;

void InputData(void){
    cin >> N >> T;
    for(int i=0; i<N; i++){
        cin >> P[i] >> S[i];
    }
}
void Solve(void){
    int i;
    long long pos;

    for(i=0; i<N; i++){
        pos = P[i] + (long long)T * S[i];
        for( ; (s.size() > 0) && (s.top() >= pos); s.pop())
        s.push(pos);
    }
    cout << s.size();
}
int main(void){
    InputData();
    Solve();
    return 0;
}
