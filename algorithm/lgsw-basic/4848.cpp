#include <iostream>
using namespace std;
#define MAXN 50000
int N;//정수
int P[MAXN]; //분모 
int C[MAXN]; //분자 
void InputData(){ 
	cin >> N; 
}
void OutputData(){
	cout << "0/1" << endl;
	for(int i=0; i<MAXN; i++){
		if(P[i] == 0) continue;
		cout << C[i] << "/" << P[i] << endl;
	}
	cout << "1/1" << endl;
}
void Solve(){
	for(int i=2; i<=N; i++){
		for(int j=1; j<i; j++){
			int index =(j*MAXN)/i;
			if(P[index] != 0) continue;
			P[index] = i;
			C[index] = j;
		}
	}
}
int main() {
	InputData();
	Solve();
	OutputData();
	
	return 0;
}
