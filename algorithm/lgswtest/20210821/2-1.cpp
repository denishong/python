#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
char c[MAXN+10];
char tmp[MAXN+10];
queue <char> q;
int cnt;
void InputData(void){
	cin >> c;
}
void PushData(){
	int k=0;
	while(!q.empty()){
		tmp[k++]= q.front();
		cout << tmp[k];
		q.pop();
	}
	for(int i=0; i<cnt; i++){
		cout << tmp;
	}
}
void Solve(){
	int depth=0;
	for(int i =0; c[i]; i++){
		if (c[i] == '<' ) depth++;
		else if( c[i] == '>' ) depth--; 
		else {
			while(c[i] != '>' && c[i] != '<'){
					q.push(c[i]);
			}
			PushData();
		}
	}
}
int main(void){
	InputData();
	Solve();
	return 0;
}
