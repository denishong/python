#include <iostream>
using namespace std;
#define MAXN 100001

int N,M,R;
int cnt=2;
bool map[MAXN][MAXN];
bool visited[MAXN];
int A[MAXN];
void DFS(int n){
    visited[n] = 1;
    for (int i = 1; i <= N; i++) {
        if (map[n][i] == 1 && visited[i] == 0){
			A[i]=cnt;
			cnt++;
            DFS(i);
        }
    }
}
void InputData(void){
	int y,x;
	cin>>N>>M>>R;
	for(int i=0; i<M; i++){
		cin>>y>>x;
		map[y][x]=1;
		map[x][y]=1;
	}
}
int main(void){
	InputData();
	A[R]=1;
	DFS(R);
	for(int i=1; i<=N; i++)
		cout<<A[i]<<endl;
	return 0;
}
