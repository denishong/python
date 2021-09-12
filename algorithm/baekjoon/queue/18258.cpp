/*baekjoon 18258 queue*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX_N 100

int main()
{

	int n,i,dt;
	char str[10];

	cin >> n;

	queue<int> q;


	for(i =0; i < n; i++ ){


			scanf("%s", str);

		if( !strcmp(str, "push") ){
			scanf("%d", &dt);
			q.push(dt);
		}else if( !strcmp(str, "front") ){
			if(!q.empty()){
				printf( "%d\n", q.front() );
			} else{
				printf("-1\n");
			}
		}else if(  !strcmp(str, "back") ){
			if(!q.empty()){
				printf( "%d\n", q.back() );
			} else{
				printf("-1\n");
			}
		}else if( !strcmp(str, "size") ){
			printf( "%ld\n", q.size() );
		}else if( !strcmp(str, "empty") ){
			printf( "%d\n", q.empty() );
		}else if( !strcmp(str, "pop") ){
			if(!q.empty()){
				printf( "%d\n", q.front() );
				q.pop();
			} else{
				printf("-1\n");
			}
		}
	}

	return 0;
}
