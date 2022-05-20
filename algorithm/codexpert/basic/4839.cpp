#include <iostream>
using namespace std;

int M;//문자 반복 최소 횟수
char str[100 + 10];//입력 문자열

void InputData(){
    int i;
	cin >> M;
	cin >> str;
    for(i = 0; str[i]; i++);
    cout << "i : " << i;
    str[i] = ' '; str[i+1] = 0;
}

void Solve(){
    int count = 1;
    for( int i = 1; str[i]; i++ ) {
        if( str[i] != str[i-1] ) {
            if( count >=M ){
                cout << str[i-1] << "(" << count << ")";
            }else{
                for( int j=0; j<count; j++ ){
                    cout << str[i-1] ;
                }
            }
            count =1;
        }else{
            count++;
        }
    } //for
    cout << endl;
}

int main() {
	InputData();//입력
	
	//여기서부터 작성
    Solve();
	
	return 0;
}
