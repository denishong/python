#include <iostream>
using namespace std;
#define MAXN ((int)1e5)
int N=3;
int X[MAXN + 10];
int Y[MAXN + 10];
int num[10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}
void DFS1(int n){
    if(n>=N){
        for(int i=0;i<N;i++){
            cout << num[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i=1; i<=6; i++){
        num[n]=i;
        DFS1(n+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    DFS1(0);
    return 0;
}
