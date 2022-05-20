#include <iostream>
using namespace std;

int main(){
	int N, K, count=0;
	int A[11];
	cin >> N >> K;
	for( int i =0; i < N; i++)
		cin >> A[i];


	for(int i = N-1; i >=0; i--){
	    count += K/A[i];
		K %= A[i];
	}
	cout << count << endl;
	return 0;
}
