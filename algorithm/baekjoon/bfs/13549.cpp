/*baekjoon 13549 숨바꼭질3 BFS*/
#include <iostream>
#include <queue>

using namespace std;

#define max 100001 

int n, k ;//  
int visit[max];
queue<int> q;


void bfs(){

	int current = n;
	while(!q.empty()) {

		int current = q.front();
		q.pop();

		if( current == k) { //k를 찾았았을 경우 

			cout << visit[k] << endl;
			break;
		}

		if( visit[current - 1] == 0 && current - 1 >=0  && current -1 < max ) {
			visit[current - 1] = visit[current] + 1;
			q.push(current - 1);
		}
		if( visit[current + 1] == 0 && current + 1 >=0  && current +1 < max ) {
			visit[current + 1] = visit[current] + 1;
			q.push(current + 1);
		}
		if( visit[current * 2] == 0 && current * 2 >=0  && current *2 < max ) {
			visit[current * 2] = visit[current];
			q.push(current * 2);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	q.push(n);

	bfs();

	return 0;
}
/*baekjoon 13549 숨바꼭질3 BFS*/
