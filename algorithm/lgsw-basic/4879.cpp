#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 5e3)
int N;
int d[MAXN+10];
void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> d[i];
	}
}
bool comp(int a, int b) { return a>b;}
void Solve(){
	sort(d, d+N,comp);
	for(int i=0; i<N; i++){
		cout << d[i] << ' ';
	}
	cout << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
