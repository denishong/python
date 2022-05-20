/*baekjoon 1260 DFS,BFS*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 10000

int N, M, V;// 정점수 , 간선수 , 시작점 
bool visited[1000+10];
struct AA{
	int s;
	int e;
};
struct AA se[MAXN+10];
void init(){
	for ( int i =0; i <= N; i++) { visited[i] = false;}
}
void DFS(int st){
	int d;
	visited[st] = true;
	cout << st << " ";
	for (int i = 1; i <= M; i++) {
	//	cout << "st, i, mat[st][i] , visited[i]" << st << " "\
			<< i << ' ' << mat[st][i] << ' ' << visited[i] << endl;
		if ( (st == se[i].s) && (visited[se[i].e] == false) ) d=se[i].e;
		else if ( (st == se[i].e) && (visited[se[i].s] == false) ) d=se[i].s;
		else continue;
		DFS(d);
	}

}
void BFS(int st){
	queue<int> q;
	visited[st] = true;
	q.push(st);

	while(!q.empty()) {
		int temp = q.front(), d;
		cout << temp << " ";
		q.pop();
		for (int i = 1; i <= M; i++) {
	//		cout << "st, i, mat[temp][i] , visited[i]" << st << " "\
				<< i << ' ' << mat[temp][i] << ' ' << visited[i] << endl;
			if (temp == se[i].s && visited[se[i].e] == false ) d=se[i].e;
			else if (temp == se[i].e && visited[se[i].s] == false ) d=se[i].s;
			else continue;

				visited[d] = true;
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
void OutputData(){
	for( int i=1; i <= M; i++){
		cout << se[i].s << " " << se[i].e << endl;
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	InputData();
	sort(se+1,se+M+1, comp);
	DFS(V);
	init();
	cout << endl;
	BFS(V);

	return 0;
}
/*baekjoon 1260 DFS,BFS*/
