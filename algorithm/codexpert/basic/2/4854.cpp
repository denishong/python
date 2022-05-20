#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e4)
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
bool comp(struct Data A, struct Data B){ return A.s < B.s;}
void Solve(){
	int s, e;
	int absent=0, present=0;
	sort(A, A+N, comp);
	s=A[0].s, e=A[0].e;
	for(int i=1; i<N; i++){
		if( A[i].s > e ) {
			if( absent < ( A[i].s - e ))  absent = A[i].s -e;
			if( present < (e-s) ) present = e -s;
			e=A[i].e, s=A[i].s;
		}else if(e < A[i].e){
			e=A[i].e;
		}
	}
	if(present < (e-s) ) present = (e-s);
	cout << present << ' ' << absent << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
