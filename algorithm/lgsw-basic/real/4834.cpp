/*[4834][실전] UNIQUENESS*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e4)
int N;

char S[MAXN + 10][20+10];
int used[MAXN + 10];
void InputData(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> S[i];
    }
}
void Solve(){
    int uniq = 1;
    for(int i=1; i<=N; i++){
        int first = 0;
        if(used[i] == 1) continue; //이미 다른 문자열과 같은 문자열임 
        for(int j=i+1; j<=N; j++){
            int r = strcmp(S[i], S[j]);
            if ( r != 0) continue;
            uniq = 0;
            used[j] = 1;
            if ( first == 0){
                cout << S[i] <<" " << i <<" " << j;
                first = 1;
            }else{
                cout << " " << j;
            }
        } 
        if(first == 1) cout << endl;
    }
    if( uniq == 1) cout <<"unique" << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[4834][실전] UNIQUENESS*/
