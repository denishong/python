#include <iostream>

using namespace std;

int main(){

	int N, K;
	int A[11];
	int i, count=0, tmp = 0;
	cin >> N >> K;

	for( int i =0; i < N; i++){
		cin >> A[i];
	}

	for(i = N-1; i >=0; i--){
		if ( tmp = K/A[i] ){
			K -= K/A[i] * A[i];
			count += tmp;
		}
	}
	//cout << "i, K, tmp, count : " << i << ' ' << K << ' ' << tmp << ' ' << count << endl;

	cout << count << endl;
	return 0;
}
