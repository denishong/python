/*baekjoon 18258 queue*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX_N 100

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n,i,dt;
	char str[10];
	cin >> n;

	queue<int> q;


	for(i =0; i < n; i++ ){

		cin >> str;

		if( !strcmp(str, "push") ){
			cin >> dt;
			q.push(dt);
		}else if( !strcmp(str, "front") ){
			if(!q.empty() ){
				cout << q.front() << endl ;
			}else{
				cout << "-1" << endl;
			}
		}else if( !strcmp(str, "back") ){
			if(!q.empty() ){
				cout << q.back() << endl;
			}else{
				cout << "-1" << endl;
			}
		}else if( !strcmp(str, "size") ){
			cout << q.size() << endl;
		}else if( !strcmp(str, "empty") ){
			cout << q.empty() << endl;
		}else if( !strcmp(str, "pop") ){
			if(!q.empty() ){
				cout << q.front() << endl;
				q.pop();
			} else {
				cout << "-1" << endl;
			}
		}
	}

	return 0;
}
