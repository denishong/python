#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 1e4)
int N;
struct TimeData{
	int s,e;
};
struct TimeData D[MAXN +10];

void InputData(void){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> D[i].s >> D[i].e ;
	}
}
bool comp(struct TimeData A, struct TimeData B){ return A.s < B.s;}
void Solve(void){
	int present=0, absent=0, s,e;
	//1.sorting
	sort(D,D+N,comp);

	s = D[0].s;
	e = D[0].e;

	for(int i=1; i<N; i++){
		if(D[i].s > e){
		if( absent < D[i].s-e) absent = D[i].s-e;
		if( present < e-s) present = e-s;
		s=D[i].s; e=D[i].e;
		}else if( D[i].e > e){
			e = D[i].e;
		}
	}
	if( present < e-s) present = e-s;
	cout << present << ' ' << absent << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
