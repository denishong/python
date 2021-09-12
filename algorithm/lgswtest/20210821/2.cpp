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
void OutputData(){
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
			if(c[i] != '>' && c[i] != '<'){
				if(c[i] >= '0' &&  c[i] <= '9'){
					cnt = atoi(&c[i]);
				}else{
					q.push(c[i]);
				}
			}
		}
	}
}
int main(void){
	InputData();
	Solve();
	OutputData();
	return 0;
}
