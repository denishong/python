#include <iostream>
using namespace std;

long long X;
long long K;

void InputData(){
	cin >> X >> K;
}

int main() {
	long long ans = 100;
	//InputData();

	//여기서부터 작성
	while( ans > 0){
		ans >>= 2;	
		cout << ans << endl;
	}
	return 0;
}
