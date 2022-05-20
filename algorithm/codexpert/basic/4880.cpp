#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 3e4)
int N;
int d[MAXN+10];
void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> d[i];
	}
}
void Solve(){
	sort(d, d+N);
	for(int i=0; i<4; i++){
		cout << d[i] << ' ';
	}
	cout << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
