/*[11724] baekjoon 연결 요소의 개수*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e3) 

int N,M,cnt=0;
int s[MAXN*MAXN], e[MAXN*MAXN];
int mat[MAXN+10][MAXN+10];
int visited[MAXN+10];

void InputData(){
	int u, v;
	cin >> N >> M;
	for (int i=0; i<M; i++){
		cin >> u >> v;
		mat[u][v] = 1;
		mat[v][u] = 1;
	}
}
void DFS(int x){
	visited[x] = 1;
	for(int i =1; i<=N; i++){
		if(mat[x][i] ==1 && visited[i] ==0){
			DFS(i);
		}
	}
}
void BFS(int x){
	int t;
	queue <int> q;
	q.push(x);
	visited[x] = 1;
	while( !q.empty()){
		t = q.front();
		q.pop();
		for(int i=1; i<=N; i++){
			if(mat[t][i] == 1 && visited[i] ==0){ 
				q.push(i);
				visited[i] =1;
			}
		}
	}
}
void Solve(){
	for(int i=1; i<=N; i++){
		if(visited[i] ==0){
			BFS(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}
int main(){
	InputData();
	Solve();
	return 0;
}
/*[11724] baekjoon 연결 요소의 개수*/
