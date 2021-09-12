/*baekjoon 1931 회의실 배정 */
#include <iostream>
#include <queue>

using namespace std;

int main(){

	int N;
	int i, count=0, tmp =0;
	int start, finish;
	cin >> N;
	queue< pair<int, int> > q;

	for( int i =0; i < N; i++){
		cin >> start >> finish;
		q.push(make_pair(start, finish));
	}

	for( i =0; i< N; i++ ){

		if( q.front().first == q.front().second ){
			count++;
			q.pop();
			if( tmp == 0 ){
				tmp = q.front().second;
				count++;
				q.pop();
			}
		}else{
			if( q.front().first >= tmp ){
				count++;
				tmp = q.front().second;
				q.pop();
			} else if( q.front().first < tmp ){
				q.pop();
			}
		}

	}//for

	cout << count << endl;
	return 0;
}
/*baekjoon 1931 회의실 배정 */
