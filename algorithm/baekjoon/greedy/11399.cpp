/* baekjoon 11399 ATM */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int N;
	int i,j, count=0, tmp =0;
	int start, finish;
	cin >> N;
	vector< int> v;

	for( int i =0; i < N; i++){
		cin >> start;
		v.push_back( start );
	}

	sort( v.begin(), v.end() );

	for( i =0; i< N; i++ ){
		tmp = 0;
		for(j =0; j<=i; j++){
			tmp += v[j];
		}
		count += tmp;
	}//for

	cout << count << endl;
	return 0;
}
/* baekjoon 11399 ATM */
