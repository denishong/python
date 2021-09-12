#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 1e3)
int N;
int used[MAXN+10];
void InputData(void){
	cin >> N;
}
int Digitsquare(int x){
	int sum =0;
	int t;
	while(x){
		t = x%10;
		sum += t*t;
		x /=10;
	}
	return sum;
}
int Happynum(int x){
	used[x] =1;	
	while(x != 1){
		x=Digitsquare(x);
		if(used[x]++) return 0;
	}
	return 1;
}
int Solve(void){
	int i;
	for(i=N; i>0; i--){
		if(Happynum(i) == 1) break;
	}
	return i;	
}
int main(void){
	int ans = -1;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}
