#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 3e4)
int N;
struct ST{
	int id;
	int score;
};
ST A[MAXN+10];
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i].score;
		A[i].id = i+1;
	}
}
bool comp(struct ST i, struct ST j){ 
	return (i.score > j.score);
}
void Solve() {
    sort(A, A+N, comp);
	for(int i=0; i<3; i++){
		cout << A[i].id << " ";
	}
	cout << endl;
}
int main() {
	InputData();
	Solve();
	return 0;
}
