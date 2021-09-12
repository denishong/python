#include <bits/stdc++.h>
using namespace std;

int N,M;
int s[200+10];
int e[200+10];
int sel[100+10];

void InputData(void){
	cin >> N >> M;
	for(int i=1; i<=M; i++){
		cin >> s[i] >> e[i];
	}
}
void Solve(void){
	int t,d;
	queue <int> q;
	q.push(1);
	sel[1]=1;
	while(!q.empty()){
		t=q.front();
		cout << t << ' ';
		q.pop();
		for(int i=1; i<=M; i++){
			if(t==s[i] && sel[e[i]]==0) d=e[i];
			else if(t==e[i] && sel[s[i]]==0) d=s[i];
			else continue;
		q.push(d);
		sel[d]=1;
		}
	}
}
int main(void){
	InputData();
	Solve();
	return 0;
}
