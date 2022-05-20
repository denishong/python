#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10010
int N;
int D[MAXN];
int Solve(){
	for(int i=0; i<N; i++){
		sort(D,D+i+1);
		cout<<D[i/2]<<endl;
	}
	return 0;
}
void InputData(){
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>D[i];
}
int main(){
	InputData();
	Solve();
	return 0;
}
