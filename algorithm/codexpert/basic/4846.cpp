#include <iostream>
#include <cstring>
using namespace std;

char str[1000000+10];//두 단계를 거쳐서 변환된 숫자
char sol[1000000+10];//원래 숫자

void InputData(){ 
    cin >> str; 
}
void OutputData(int k, int ret){
    if (ret == 0) cout << k << ". IMPOSSIBLE" << endl;
    else cout << k << ". " << sol << endl;
}

int Solve(){
	int borrow = 0, temp = 1, i;
	int len = strlen(str); sol[len] = 0;
	sol[len-1] = str[len-1];

	for( i = len-2; i >= 0; i--){
		temp = str[i] - sol[i+1] - borrow;

		if( temp < 0) {
			temp += 10; borrow =1;
		}else{
			borrow = 0;
		}
		sol[i] = (char)(temp + '0' );
	}
	if( temp == 0) return 0; //failue
	return 1; //success
}

int main() {
    int ret, i;
    for (i = 1; ;i++) {
        InputData();//입력
        if (str[0] == '0') break;
		
        //여기서 부터 작성
		ret = Solve();	
        OutputData(i, ret);//출력
    }
    return 0;
}
