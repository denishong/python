#include <iostream>
using namespace std;
#define MAXN ((int) 1e5 +10)
int N;
int S[MAXN];
int pat[MAXN];

void InputData(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S[i];
    }
}
void Solve(){
    int cnt=0, seq=1;
    int max=0;
    for(int i=1; i<N; i++){
        if(S[i] != S[i-1]) seq++;
        else{
            pat[cnt++] = seq;
            seq =1;
        }
    }

    pat[cnt++] = seq;
    for(int i=0; i<cnt; i++)
        cout << "pat : " << pat[i] << ' ';
    if(cnt <= 3){
        for(int i=0; i<cnt; i++) max += pat[i];
    }else{
        for(int i=0; i<cnt-2; i++){
            seq=0;
            for(int j=i; j<i+3; j++){
                seq += pat[j];
            }
        if(max < seq) max = seq;
        }
    }
    cout << max << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
