#include <iostream>
using namespace std;

int N;
int A[4] = {10, 50, 100,500};

void InputData(){
	cin >> N;
}

int Solve(){
    int count=0;
    for(int i = 3; i>=0; i--){
        if( int tmp = N/A[i] ){
            N -= N/A[i] * A[i];
            count += tmp;
        }
    }
    return count;
}


int main(){
	int ans = 0;

	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = Solve();
	cout << ans << endl;// 출력하는 부분

	return 0;
}
