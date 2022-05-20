#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int N,P;
int R[MAXN+10];

void InputData(void){
	cin >> N >> P;
}

int Solve(void){
	int sol, next;
	R[N]=1;
	next = N;

	for(int i=2; ; i++){
		next = (next*N)	% P;
		if(R[next]){
			sol = i-R[next];
			break;
		}
		R[next] = i;
	}
	return sol;
}
int main(void){
	int ans;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}
