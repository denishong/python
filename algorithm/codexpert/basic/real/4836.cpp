/*[실전][4836]순환 순열*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int	N,P;
int R[MAXN+10];

void InputData(){
	cin >> N >> P;
}

int Solve(){
	int i, next=N, sol =0;
	R[N]=1;
	for(i=2; ; i++){
		next = (next*N) % P;
		if(R[next]){ //순환 찾음 
			sol=i-R[next];
			break;
		}
		R[next]=i;
	}
	return sol; 
}

int main()
{
	int ans=0;
	InputData();
	ans = Solve();	
	cout << ans << endl;
	return 0;
}
/*[실전][4836]순환 순열*/
