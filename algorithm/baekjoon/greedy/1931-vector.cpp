#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int N;
	int i, count=0, tmp =0;
	int start, finish;
	cin >> N;
	vector< pair<int, int> > v;

	for( int i =0; i < N; i++){
		cin >> start >> finish;
		v.push_back(make_pair( finish, start));
	}

	sort( v.begin(), v.end() );

	for( i =0; i< N; i++ ){

		if( v[i].first == v[i].second ){
				tmp = v[i].first;
				count++;
		}else{
			if( v[i].second >= tmp ){
				count++;
				tmp = v[i].first;
			}
		}

	}//for

	cout << count << endl;
	return 0;
}
