/*[4860][BFS]너비우선1*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
#define MAXM ((int) 2e2)

int N;//정점
int M;//간선
int s[MAXM+10];//간선 시작점 
int e[MAXM+10];//간선 끝점
int sel[MAXN+10];//정점 지나간 적있는 지 저장 

void InputData()
{
	cin >> N >> M;
	for(int i=1; i<=M; i++)
	{
		cin >> s[i] >> e[i];
	}
}
void Solve(){
	int t, d, j = 0;
	queue <int> q;
	q.push(1);
	sel[1] = 1;
	while( !q.empty()){
		t = q.front();
		cout << t << ' ';
		q.pop();
		for(int i=1; i<=M; i++){
			if((t==s[i]) && (sel[e[i]] ==0)) d = e[i];
			else if(( t==e[i]) && (sel[s[i]] ==0)) d = s[i];
			else continue;

			q.push(d);
			sel[d] =1;
		}
	}
}
int main(void)
{
	InputData();
	Solve();
	return 0;
}
/*[4860][BFS]너비우선1*/
