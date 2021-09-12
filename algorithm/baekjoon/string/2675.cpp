#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 2e1)
int T;
int R;
char S[MAXN+5];
int main(){
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> R >> S;
		for(int j=0; S[j]; j++){
			for(int r=0; r<R; r++){
				cout << S[j];
			}
		}
	cout << endl;
	}
	return 0;
}
