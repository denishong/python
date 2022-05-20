#include <iostream>
using namespace std;

#define MAXN 5000
int N;
int A[MAXN+10];

void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
}

void Solve(){
	int tmp;
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(A[i] > A[j] ){
				tmp = A[j];
				A[j] = A[i];
				A[i] = tmp;
			}
		}
	}
	for(int i=0; i<N; i++){
		cout << A[i] << " ";
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
