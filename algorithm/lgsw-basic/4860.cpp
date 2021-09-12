#include <iostream>
#include <queue>
using namespace std;

int N, M;
int s[200+10];
int e[200+10];
int sol[100+10];

int visited[100+10];

void InputData()
{
	cin >> N >> M;
	for(int i=1; i<=M; i++)
	{
		cin >> s[i] >> e[i];
	}
}
#if 0
void InputData(){
	int x,y;

	cin >> N >> M;
	for( int i=0; i < M; i++){
		cin >> x >> y;
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
}
#endif
void OutputData()
{
	cout << sol[0];
	for(int i=1; i<N; i++)
	{
		cout << " " << sol[i];
	}
} 

void BFS(int st){
	queue<int> q;
	int j =0;
	visited[st] = true;
	q.push(st);

	while(!q.empty()) {
		int t, d;
		t = q.front();
		sol[j++] = t;
		//cout << t << " ";
		q.pop();
		for (int i = 1; i <= M; i++) {
			if ((t == s[i] ) && (visited[e[i]] == false) ) d = e[i] ; 
			else if( (t == e[i] ) && (visited[s[i]] == false) ) d = s[i];
			else continue;
				q.push(d);
				visited[d] = true;
		}   
	}   
}

int main()
{
	InputData();
	BFS(1);
	OutputData();
	return 0;
}
