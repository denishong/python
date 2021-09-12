#include <iostream>
using namespace std;

int N;
int A[50000 +10];
int T;
int B[10000+10];

void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> B[i];
	}
}
void OutputData(){
	for(int i=0; i<T; i++){
	cout << B[i] << endl;
	}
}
int Binary_Search(int s, int e, int d){
	int m;
	while(s <= e){
		m=(s+e)/2;
		if(A[m] == d){
			return m+1;
		}else if( A[m] > d){
			e = m-1;
		}else{
			s = m+1;
		}
	}
	return 0;
}
void Solve(){
	int temp;
	for(int i=0; i<T; i++){
		temp = Binary_Search(0, N-1, B[i]);
		B[i] = temp;
	}	
}
int main(){
	InputData();
	Solve();
	OutputData();
	return 0;
}
