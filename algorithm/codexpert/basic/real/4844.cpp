#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
#define INF 1000000

int N; 
int A[MAXN +10];

void InputData(void){
	int i;
	cin >> N; 
	for(i=0; i<N; i++){
		cin >> A[i];
	}
}

int DigitSum(int x){
	int sum=0;

	while(x >0){
		sum += x%10;
		x /= 10;
	}
	return sum;
}
int DigitRoot(int x){
	while(x >= 10){
		x = DigitSum(x);
	}
	return x;
}

int Solve(){
	int maxdigit=0, maxv=INF;
	for(int i=0; i<N; i++){
		int r= DigitRoot(A[i]);
		if( (maxdigit < r) || ((maxdigit == r) && (maxv > A[i])) ){
			maxdigit = r;
			maxv = A[i];
		}  
	}
	return maxv;
}

int main(void){
	int ans;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}
