/*baekjoon 1697 숨바꼭질 BFS*/
#include <iostream>
#include <queue>
using namespace std;
#define MAXN 100001 

int N, K ;//수빈,동생 
int visit[MAXN];
queue<int> q;

bool isInside(int a){
	return ( a>=0 && a< MAXN);}

void BFS(){
	int current;
    q.push(N);
	while(!q.empty()) {
		current = q.front();
		q.pop();

		if( current == K) { //k를 찾았았을 경우 
			cout << visit[K] << endl;
			break;
		}

		if( visit[current - 1] == 0 && current - 1 >=0  && current -1 < MAXN ) {
			visit[current - 1] = visit[current] + 1;
			q.push(current - 1);
		}
		if( visit[current + 1] == 0 && current + 1 >=0  && current +1 < MAXN ) {
			visit[current + 1] = visit[current] + 1;
			q.push(current + 1);
		}
		if( visit[current * 2] == 0 && current * 2 >=0  && current *2 < MAXN ) {
			visit[current * 2] = visit[current] + 1;
			q.push(current * 2);
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
	BFS();

	return 0;
}
/*baekjoon 1697 숨바꼭질 BFS*/
