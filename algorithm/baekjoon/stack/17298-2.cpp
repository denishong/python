#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e6)

int N;
int D[MAXN]; // input data
int rlt[MAXN];// D[i]의 오큰수는 rlt[i]에 저장 
void InputData(){
    cin >> N;
    for(int i =0; i < N; i++){
        cin >> D[i];
    }
}
void Solve()
{
    stack<int> stkNotFound; //오큰수를 아직 찾지 못한 수들 
    stack<int> stkNotFoundIdx;//오큰수를 아직 찾지 못한 수들의 인덱스 
    for(int idx =0; idx < N; idx++){
        cout << "stkNotFound.size : " << stkNotFound.size() << endl;
    
        while ((stkNotFound.size() > 0) && (stkNotFound.top() < D[idx])){
            rlt[stkNotFoundIdx.top()] = D[idx];
            stkNotFound.pop();
            stkNotFoundIdx.pop();
       }
        stkNotFound.push(D[idx]);
        stkNotFoundIdx.push(idx);
    }
    while(stkNotFoundIdx.size() > 0 ){
        rlt[stkNotFoundIdx.top()] = -1;
        stkNotFoundIdx.pop();
    }
}
void OutputData(){
    rlt[N-1] = -1; /*마지막 수의 오큰수는 항상 -1*/
    for( int i =0; i < N; i++) {
        cout << rlt[i] << ' ';
    }
}
int main(void){
    InputData();
    Solve();
    OutputData();
    return 0;
}
