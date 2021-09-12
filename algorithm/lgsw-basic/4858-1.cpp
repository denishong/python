#include <bits/stdc++.h>
using namespace std;

#define MAXN 13

int N;
int chess[MAXN+5][MAXN+5];
int sol;
int col[MAXN + 5];
int diag1[MAXN*2];
int diag2[MAXN*2];

void search(int y){
    if(y >= N){ 
        sol++; 
        return;
    }
    for(int x=0; x<N; x++){
        if(col[x] || diag1[x+y] || diag2[x-y+N-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+N-1] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+N-1] = 0;
    }
}

void InputData(){
	cin >> N;
}

void Solve(){
    search(0);
}

int main(){
	InputData();
    Solve();
	cout << sol << endl;

	return 0;
}
