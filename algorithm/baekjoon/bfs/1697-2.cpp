/*baekjoon 1697 숨바꼭질 BFS*/
#include <iostream>
#include <queue>
using namespace std;
#define MAXN 100001 

int N, K ;//수빈,동생 
int visit[MAXN];
queue<int> q;

bool isInside(int a){
	return ( a>=0 && a< MAXN);
}

int BFS(){
    q.push(N);
	while(!q.empty()) {
	    int	cur = q.front();
		q.pop();

		if( cur == K) return visit[K];//K를 찾았을 때 
        for( int nx : {cur-1, cur+1, cur*2}){
		    if( isInside(nx) &&  (visit[nx] == 0) ) {
			    visit[nx] = visit[cur] + 1;
			    q.push(nx);
		    }
        }
	}
}
void InputData(){
	cin >> N >> K;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	InputData();
	cout << BFS() << endl;

	return 0;
}
/*baekjoon 1697 숨바꼭질 BFS*/
