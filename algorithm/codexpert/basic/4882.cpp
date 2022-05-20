#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e6)
char S[MAXN+10];
void InputData(void){
	cin >> S;
}
int Solve(){
	int count=0;
	int sum=0;
	for(int i=0; S[i]; i++){
		if(S[i] == '('){
			count++;
		}else{
			count--;
			if(S[i-1] == '('){
				sum += count;
			}else{
				sum++;
			}	
		}
	}
	return sum;
}
int main(void){
	int ans=-1;
	InputData();
	ans=Solve();
	cout << ans <<endl;
	return 0;
}
