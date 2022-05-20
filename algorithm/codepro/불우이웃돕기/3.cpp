#include <bits/stdc++.h>
using namespace std;
int C[10];
int sol[10];
int num[10]={1,5,10,50,100,500,1000,3000,6000,12000};
int N;
int Solve(){
	int totalcnt,sum=0,cnt;
	for(int i=0; i<10; i++){
		sum += C[i] * num[i];
	}
	sum -= N;
   cout << "sum : "	 << sum << endl;
	for(int i=9; i>=0; i++){
		cnt = sum/num[i];
		if(cnt > C[i]) cnt = C[i];
		sum -= cnt * num[i];
		sol[i] = C[i] - cnt;
		totalcnt += sol[i];
	}
	return totalcnt;
}
void InputData(){
	cin >> N;
	for(int i=0; i<10; i++){
		cin >> C[i];
	}
}
void OutputData(){
	for(int i=0; i<10; i++){
		cout << sol[i] << ' ';
	}
	cout << endl;
}
int main() {
	InputData();
	cout << Solve() << endl;
	OutputData();
	return 0;
}
