#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
int N;
struct Data{
	int s,e;
};
struct Data A[MAXN+10];
void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i].s >> A[i].e;
	}
}
bool comp(struct Data A, struct Data B){ return A.e < B.e;}
void Solve(){
	int cnt,e;
	sort(A,A+N,comp);
	cnt = 1;
	e = A[0].e;
	for(int i=1; i<N; i++){
		if( e < A[i].s ){
			cnt++;
			e = A[i].e;
		}
	}	
	cout << cnt << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
