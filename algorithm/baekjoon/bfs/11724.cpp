#include <iostream>
#include <queue>

using namespace std;
#define MAXN 1000

int N,M,cnt=0;
int s[MAXN*MAXN], e[MAXN*MAXN];
int visited[MAXN+10];

void InputData(){
	cin >> N >> M;
	for (int i=0; i<M; i++){
		cin >> s[i] >> e[i];
	}

}
void BFS(int x){
	int t, d,j=0;
	queue <int> q;
	q.push(x);
	visited[1] = 1;
	while( !q.empty()){
		t = q.front();
		q.pop();
		for(int i=1; i<=M; i++){
			if((t==s[i]) && (visited[e[i]] ==0)) d = e[i];
			else if(( t==e[i]) && (visited[s[i]] ==0)) d = s[i];
			else continue;

			q.push(d);
			visited[d] =1;
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
