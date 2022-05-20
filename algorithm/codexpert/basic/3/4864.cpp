#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 2e4)
int N;
char str[MAXN+10];
void InputData(){
	cin >> N >> str;
}
void Solve(){
	int depth=0;
	for(int i=0; str[i]; i++){
		if(str[i] == '<') depth++;
		else if(str[i] == '>') depth--;
		else if( depth == N){
			while( (str[i] != '<') && (str[i] != '>') ){
				cout << str[i++];
			}
		cout << ' ';
		i--;
		}
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
