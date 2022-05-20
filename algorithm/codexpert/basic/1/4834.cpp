#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e4)
int N;
char S[MAXN+10][20+4];
int used[MAXN+10];
void InputData(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> S[i];
	}	
}
void Solve(){
	int r;
	int uniq=0;
	for(int i=1; i<N; i++){
		int first=0;
		if(used[i]==1) continue;
		for(int j=i+1; j<=N; j++){
			if(used[j]==1) continue;
			r = strcmp(S[i],S[j]);
			if(r != 0) continue;
			used[j] =1;
			uniq =1;
			if(first == 0){
				cout << S[i] << ' ' << i << ' ' << j;
			}else{
				cout <<' ' << j;
			}
			first =1;
		}
		if(first==1) cout << endl;
	}
	if(uniq==0) cout << "unique" << endl;
}
int main(){
	InputData();
	Solve();
	return 0;
}
