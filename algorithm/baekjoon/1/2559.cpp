#include <iostream>
using namespace std;
 
const int MAX = 100000 + 1;
 
int A[MAX];
long long int res;
int N, K;
void Solve(){
	//초기 배열1 설정
    int s = 0;
    long long int sum = 0;
    for (int i = s; i < s+K; i++) {
        sum += A[i];
    }
    res = sum;
 
    //배열 탐색
    while (true) {
        //기존 합에 앞에 부분을 뺀다
        sum -= A[s];
        //배열의 범위를 벗어날 경우
        if (s+K >= N) {
            break;
        }
        //합에 뒷부분을 더한다
        sum += A[s+K];
        if (sum > res) {
            res = sum;
        }
        //다음 배열 index
        s++;
    }
 
    //출력
    cout << res;
}

void InputData(){
    //입력
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}
int main(){
	InputData(); 
	Solve();
	return 0; 
}
