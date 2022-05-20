#include <iostream>
using namespace std;

int N;//전체 페이지 수
int P;//뜯고자 하는 페이지 번호
int page1, page2, page3;//결과

void input_data(){
	cin >> N >> P;
}

void output_data(){
    cout << page1 << " " << page2 << " " << page3 << endl;
}

void Solve(){
    int a,b,c;
    if( P <  N/2 ){
        if( P%2 == 1 ){
            a = P+1;
            b = N - P;
            c = N + 1 -P;
        }else{
            a = P - 1;
            b = N - P + 1;
            c = N - P + 2;
        }
    }else{
        if( P%2 == 1 ){
            a = N - P;
            b = N - P + 1;
            c = P + 1;
        }else{
            a = N - P + 1;
            b = N - P + 2;
            c = P - 1;
        }
    }
    page1 = a;
    page2 = b;
    page3 = c;
}

int main() {
	input_data();//입력
	
	//여기서부터 작성
    Solve();
	
	output_data();//출력
	return 0;
}
