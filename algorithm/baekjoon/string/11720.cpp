#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)

int main(){
    int N;
    char D[MAXN+10];
    int total=0;
    cin >> N >> D;
    for(int i=0; i<N; i++){
        total += D[i] - '0';
    }
    cout << total << endl;
    return 0;
}
