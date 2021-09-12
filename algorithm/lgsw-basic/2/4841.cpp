#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
int K;
int N;
int T[MAXN+10];
char Z[MAXN+10];
void InputData(void){
	cin >> K;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> T[i] >> Z[i];
	}
}
int Solve(){
	int sum=0;
	for(int i=0; i<N; i++){
		sum +=T[i];
		if(sum >210) break;
		if(Z[i] =='T'){
			if(++K>8) K=1;
		}
	}
	return K;
}
int main(void){
	int ans=-1;
	InputData();
	ans=Solve();
	cout << ans << endl;
	return 0;
}
