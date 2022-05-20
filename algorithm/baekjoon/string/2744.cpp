/*[baekjoon] 2744 대소문자 바꾸기*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
char str[MAXN+10];
void InputData(){
    cin >> str ;
}
void Solve(){
    for(int i=0; str[i]; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            //cout << str[i] - ('a'-'A');
            printf("%c", str[i] - ('a'-'A'));
        }else if( str[i] >= 'A' && str[i] <= 'Z'){
            printf("%c", str[i] + ('a'-'A'));
            //cout << str[i] + ('a'-'A');
        }
    }
    cout << endl;
}
int main(){
    InputData();
    Solve();
	return 0;
}
/*[baekjoon] 2744 대소문자 바꾸기*/
