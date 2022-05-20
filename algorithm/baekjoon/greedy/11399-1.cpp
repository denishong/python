/* baekjoon 11399 ATM */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N;
    int A[1001];
	int sum=0, ans =0;
	cin >> N;

	for( int i =0; i < N; i++){
		cin >> A[i];
	}

	sort( A, A+N );

	for( int i =0; i< N; i++ ){
		sum += A[i];
		ans += sum;
	}

	cout << ans << endl;
	return 0;
}
/* baekjoon 11399 ATM */
