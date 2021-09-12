#include <iostream>
using namespace std;
#define MAXN ((int) 1e4)

int N;
struct ST{
	int id, score; //idea, score
};

ST A[MAXN+10];
void InputData(){
	cin >> N;
	for(int i=0; i < N; i++){
		cin >> A[i].score;
		A[i].id = i+1;
	}
}
void OutputData(){
	for(int i=0; i<3; i++){
		cout << A[i].id << " ";
	}
	cout << endl;
}
void Solve(){
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N-1; j++){
			if(A[i].score < A[j].score){
				struct ST temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}
int main(){
	InputData();
	Solve();
	OutputData();
	return 0;
}
