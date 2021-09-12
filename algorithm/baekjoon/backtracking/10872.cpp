#include <bits/stdc++.h>
using namespace std;

int N, M;
char a[20];
bool chk[20];
using namespace std;
 
void permutation(int depth){
    if (depth == M){
        cout << a << '\n';
        return;
    }
    for (int i=0; i<N; ++i){
        if (chk[i]) continue;
        a[depth * 2] = i + '1';
        chk[i] = true;
        permutation(depth + 1);
        chk[i] = false;
    }
 
}
void InputData(){
    cin >> N >> M;
} 
void Solve(){
    for (int i=0; i<2*M; ++i) a[i] = ' ';
    permutation(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	InputData();
	Solve();
    return 0;
}
