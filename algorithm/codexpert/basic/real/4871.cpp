/*[4871][실전] 서투른 암소*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e5)
char str[MAXN+10];
void InputData(){
    cin >> str;
}
int Solve(){
    int ans = 0, depth = 0;
    for( int i=0; str[i]; i++){
        if( str[i] == '(' ) depth++;
        else depth--;

        if(depth < 0 ){
            ans++;
            depth = 1;
        }
    }
    return ans + depth/2;
}
int main(){
    int ans = -1;
    InputData();
    ans = Solve();
    cout << ans << endl;
    return 0;
}
/*[4871][실전] 서투른 암소*/
