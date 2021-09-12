/*baekjoon 1712 손익분기점 */
#include <iostream>

using namespace std;

int main(){

	long long A,B,C;
	long long cnt=1;
	long long BEP=0;

	cin >> A >> B >> C;

	if( C - B < 0) {
		cout << -1 << endl;
	}else{
		while(1){	
			if( A  < (C -B) * ++cnt ){
			break;
			}else{
			}
		}
				cout << cnt << endl;

	}
	return 0;
}
/*baekjoon 1712 손익분기점 */
