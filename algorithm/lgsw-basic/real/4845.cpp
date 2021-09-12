/*[실전][4845]행복한 수*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int) 1e3)
int	N;
int used[MAXN + 10];

void InputData(){
	cin >> N;
}

void OutputData(){
	for( int i=0; i<N; i++){
	printf("\n");
	}
}
int DigitSquare(int x){
	int sum=0;
	while(x){
		int num = x%10;
		sum += num * num;
		x /=10;
	}
	return sum;
}
int HappyNum( int x){
	used[x] = 1;
	while( x != 1){
		x = DigitSquare(x);
		if( used[x]++ ) return 0;
	}
	return 1;
}
int Solve(){
	int i;
	for( i=N; i>0; i--) {
		if (HappyNum(i) == 1) break;
	}
	return i; 
}

int main()
{
	int ans=-1;
	InputData();
	ans = Solve();	
	cout << ans << endl;
	return 0;
}
/*[실전][4845]행복한 수*/
