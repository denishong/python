#include <iostream>
using namespace std;

#define MAX (5)
int N;//정수 개수
int A[20 + 5];//정수
int queue[MAX];
int Rp = 0, Wp = 0;

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

int In_Queue(int d) {
	//작성
    if ( Wp >= MAX) return 0;
    queue[Wp++] = d;
    return 1;
}

int Out_Queue() {
	//작성
    if ( Wp == Rp ) return 0;
    int p = queue[Rp++];
    return p;
}

void Solve() {
	for (int i = 0; i < N; i++) {
		if (A[i] > 0) {
			int r = In_Queue(A[i]);
			if (r == 0) cout << "-1 ";
		}
		else {
			int r = Out_Queue();
			if (r == 0) cout << "-1 ";
			else cout << r << " ";
		}
	}
	cout << endl;
}

int main() {
	InputData();
	Solve();
	return 0;
}
