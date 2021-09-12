#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 2e4)
int N;
char S[MAXN+10];

void InputData(void){
    cin >> N >> S;
}
void Solve(){
    int depth=0;
    for(int i=0; S[i]; i++){
        if(S[i] == '<') depth++;
        else if(S[i] == '>') depth--;
        else if(depth == N){
            while( (S[i] != '<') && (S[i] != '>')){
                cout << S[i++];
            }
            cout << ' ';
            i--;
        }
    }
}
int main(void){
    InputData();
    Solve();
    return 0;
}
