#include <iostream>
using namespace std;

#define MAXN ((int)3e4) 
int N;
int A[MAXN+10];
void OutputData(){
	for(int i=0; i<N; i++){
		cout << A[i];
	}
	cout << endl;
}
void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
}

void Solve(){
	int tmp;
	for(int i=0; i<4; i++){
		for(int j=i+1; j<N; j++){
			if(A[i] > A[j] ){
				tmp = A[j];
				A[j] = A[i];
				A[i] = tmp;
				OutputData();
			}
		}
	}
	for(int i=0; i<4; i++){
		cout << A[i] << " ";
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
