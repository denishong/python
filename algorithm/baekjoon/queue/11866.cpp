/*baekjoon 18258 queue*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX_N 100
queue<int> q;
queue<int> qb;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int i,j,tmp;
	int N; // N명 
	int K; //K번째 제거 
	int Kth;
	cin >> N;
	cin >> K;



	for(i =1; i <= N; i++ ){
		q.push(i);
	}

while( q.size() ){
	for(i=1; i<= N; ++i){
		Kth = i%K;
		if( !(Kth) ) {
			cout << "k th: " << i << '\n';
			q.pop();
			continue;
		}
		tmp = q.front();
		cout << "tmp: " << tmp << '\n';
		q.pop();
		qb.push(tmp);
	}		
	N = qb.size();
	
}


	return 0;
}
