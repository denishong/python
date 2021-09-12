/*[baekjoon][1003]피보나치 함수*/
#include <bits/stdc++.h>
using namespace std;

int T;
int N[40+10];
int cnt0, cnt1;
void InputData(void){
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N[i];
	}
}
int fibonacci(int n) {
    if (n == 0) {
		cnt0++;
        return 0;
    } else if (n == 1) {
		cnt1++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
void Solve(void){
	for(int i=0; i<T; i++){
		cnt0=0;
		cnt1=0;
		fibonacci(N[i]);
		cout << cnt0 << ' ' << cnt1 << endl;
	}
}
int main(void){
	InputData();
	Solve();
	return 0;
}
/*[baekjoon][1003]피보나치 함수*/
