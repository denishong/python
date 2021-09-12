#include <iostream>
#include <algorithm>
using namespace std;

int N;//자료 개수
int A[30000 + 10];//자료

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

void OutputData() {
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
bool comp(int i, int j) { return (i < j); }

int main() {
	InputData();//입력
	//작성
	sort(A, A+N, comp);
	OutputData();//출력
	return 0;
}
