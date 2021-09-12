#include <iostream>
using namespace std;

long long X;
long long K;

void InputData(){
	cin >> X >> K;
}
long long Solve() {
	long long Y = 0;
	for( int i = 0; (K > 0) && ( i < 64); i++) {
		if( (( X >> i) & 1) == 0) {
			Y |= (K & 1) << i;
			K >>= 1;
		}
	}
	return Y;
}
int main() {
	long long ans = -1;
	InputData();
	ans = Solve();	
	cout << ans << endl;
	return 0;
}
