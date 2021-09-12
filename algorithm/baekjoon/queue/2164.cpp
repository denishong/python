/*baekjoon 18258 queue*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX_N 100
queue<int> q;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int i,n,tmp;
	cin >> n;



	for(i =1; i <= n; i++ ){
		q.push(i);
	}

	while( 1 ){
		if( q.size() ==1)
			break;

		q.pop();
		tmp = q.front();	
		q.pop();
		q.push(tmp);
	}

	cout << q.front();
		
	return 0;
}
