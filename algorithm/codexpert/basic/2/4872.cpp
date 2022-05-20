/*[4872] A9: [1주차][03과-이진탐색][기본] 숫자 찾기 (이진탐색)*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 5e4)
#define MAXT ((int) 1e4)
int N;
int A[MAXN+10];
int T;
int B[MAXT+10];
void InputData(void){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> B[i];
	}
}
int BinarySearch(int s, int e, int d){
	int m;
	while(s<=e){
		m=(s+e)/2;
		if(A[m]==d) return m+1;
		else if(A[m]>d) e = m-1;
		else if(A[m]<d) s= m+1;
	}
	return 0;
}
void Solve(void){
	int ans=-1;
	for(int i=0; i<T; i++){
		ans=BinarySearch(0,N-1,B[i]);
		cout << ans <<endl;
	}
}
int main(void){
	InputData();
	Solve();
	return 0;
}
/*[4872] A9: [1주차][03과-이진탐색][기본] 숫자 찾기 (이진탐색)*/
