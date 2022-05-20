#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e3)
int N;
int A[MAXN+10];
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i];
	}
}
bool comp(int a, int b) { return a<b;}
int Solve(void){
	int sum=0;
	//1. sorting	
	sort(A,A+N,comp);
	//2.A[0] !=0 return 1;
	if(A[0] !=1) return 1;
	for(int i=0; i<N; i++){
		if(sum+1 < A[i]) break;	
		sum += A[i];
	}
	return sum+1;
}
int main(void){
	int ans=-1;
	InputData();
	ans=Solve();
	cout << ans << endl;
	return 0;
}
