#include <iostream>
using namespace std;
#define MAXN ((int)5e4+10)
int N;
struct st{
    int X,ID;
};
struct st A[MAXN];
int check[MAXN];
int maxIDcnt;
void InputData(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >>A[i].X >> A[i].ID;
    }
}
void countID(void){
    int i,j, cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<cnt; j++){
            cout << "j : " << j << endl;
            if(check[j] == A[i].ID) break;
        }
        if(j==cnt) check[cnt++] = A[i].ID;
            cout << "i: " << i << " j: " << j << " cnt:"  << cnt << " check[j]: " << check[j] << endl;
    }
    cout << cnt << endl;
}
void Solve(void){
    countID();
}
int main(void){
    InputData();
    Solve();
    return 0;
}
