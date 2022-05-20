/*[4870][실전] 오타*/
#include <iostream>
using namespace std;
#define MAXN ((int) 1e5)

char str[MAXN+10];
void InputData(){
    cin >> str;
}
int Solve(){
	int depth=0, open=0, close=0;
	for(int i=0; str[i]; i++){
		if(str[i] == '('){
			depth++;
			open++;
		}else{
			depth--;
			close++;
		}
		if(depth == 1) open=0;
		if(depth < 0) return close;
	}
	return open;
}
int main(){
    int ans = -1;
    InputData();
	ans = Solve();
    cout << ans << endl;
    return 0;
}
/*[4870][실전] 오타*/
