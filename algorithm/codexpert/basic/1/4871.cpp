#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e6)
char S[MAXN+10];
void InputData(){
	cin >> S;
}
int Solve(void){
	int depth=0, ans=0;
	for(int i=0; S[i]; i++){
		if(S[i] == '('){
			depth++;
		}else{
			depth--;
		}
	
		if(depth < 0){
			depth =1;
			ans++;
		}
	}
	return ans+depth/2;
}
int main(void){
	int ans =-1;
	InputData();
	ans=Solve();
	cout << ans << endl;
	return 0;
}
