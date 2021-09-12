#include <iostream>
#include <algorithm>
using namespace std;

int N;

void InputData(){
	cin >> N;
}

bool Comp(int i, int j){ return( i < j );}
int Kaprekar(int num){
    int d[4];
    for( int i = 0; i < 4; i++){
        d[i] = num % 10;
        num /= 10;
    }
    sort(d, d+4, Comp);
    return (d[3]*1000 + d[2]*100 + d[1]*10 + d[0]) - 
           (d[0]*1000 + d[1]*100 + d[2]*10 + d[3]);
}

int Solve(){
    int cnt = 0, num = N;

    while( num != 6174 ){
        num = Kaprekar(num);
        cnt++;
    }
    return cnt;
}

int main(){
	int ans = -1;
	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = Solve();
	cout << ans << endl;// 출력하는 부분

	return 0;
}
