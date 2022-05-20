#include <iostream>
#include <queue>
using namespace std;
#define MAXN (int)2e4+10
#define INF MAXN*MAXN
int map[MAXN][MAXN];
int visited[MAXN];
int V,E,K;
int A[MAXN];
int B[MAXN];
int T[MAXN];
queue<int>q;
void BFS(int s){
	//1.초기화 
	for(int i=1; i<=V; i++) visited[i]=INF;
	visited[s]=0;
	//2.큐에 초기값 입력 
	q.push(s);
	//3.반복문 

	for(int i=1; i<=V; i++) cout << visited[i] << ' ' << endl;
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		for(int i=1; i<=V; i++){
			if(visited[i] <= (visited[tmp]+map[tmp][i])) continue;
			visited[i] = (visited[tmp]+map[tmp][i]);
            cout << "i,tmp, visited[i],visited[tmp] :" << i << ' ' << tmp << ' ' << visited[i] <<' ' <<visited[tmp]<< endl;
			q.push(i);
		}
	}
	//4.실패 
	for(int i=1; i<=V; i++){
		cout << visited[i] << endl;
	}
}
void Solve(){
	int ret;
	for(int i=1; i<=V; i++){
		for(int j=1; j<=V; j++){
			map[i][j]=INF;
		}
	}
	for(int i=0; i<E; i++) map[A[i]][B[i]]=map[B[i]][A[i]]=T[i];
	BFS(K);
}
void InputData(){
	cin >> V >> E;
	cin >>K; 
	for(int i=0; i<E; i++){
		cin >> A[i] >> B[i] >> T[i];	
	}
}
int main(){

	InputData();
	Solve();
	return 0;
}
