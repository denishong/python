/*baekjoon 1260 DFS,BFS*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e3) 
#define MAXM ((int)1e4) 
int N, M, V;// 정점수 , 간선수 , 시작점 
bool visited[MAXN+10];
struct AA{
	int s;
	int e;
};
struct AA se[MAXM+10];
void init(){
	for ( int i =0; i <= N; i++) { visited[i] = 0;}
}
void DFS(int st){
	int d;
	visited[st] = 1;
	cout << st << " ";
	for (int i = 1; i <= M; i++) {
		if ( (st == se[i].s) && (visited[se[i].e] == 0) ) d=se[i].e;
		else if ( (st == se[i].e) && (visited[se[i].s] == 0) ) d=se[i].s;
		else continue;
		DFS(d);
	}
}
void BFS(int st){
	queue<int> q;
	visited[st] = 1;
	q.push(st);

	while(!q.empty()) {
		int temp = q.front(), d;
		cout << temp << " ";
		q.pop();
		for (int i = 1; i <= M; i++) {
			if (temp == se[i].s && visited[se[i].e] == 0) d=se[i].e;
			else if (temp == se[i].e && visited[se[i].s] == 0) d=se[i].s;
			else continue;

				visited[d] = 1;
				q.push(d);
			}
		}
}
void InputData(){
	cin >> N >> M >> V;
	for( int i=1; i <= M; i++){
		cin >> se[i].s >> se[i].e;
	}
}
bool comp(struct AA a, struct AA b)
{	
	if(a.s==b.s)
		return a.e < b.e;
	else 
		return a.s < b.s;
}
int main(){
	InputData();
	sort(se,se+M, comp);
	DFS(V);
	init();
	cout << endl;
	BFS(V);
	cout << endl;
	return 0;
}
/*baekjoon 1260 DFS,BFS*/
