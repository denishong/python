#include <iostream>
using namespace std;
int N;
int D[1000001];
void Solve(){
	D[1]=1;
	D[2]=2;
	for(int i=3; i<=N; i++){
		D[i]=(D[i-2]+D[i-1])%15746;
	}
	cout<<D[N]<<endl;
}
int main(){
    cin >> N;
	Solve();
    return 0;
}
