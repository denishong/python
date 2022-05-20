/*[실전][4843]할부*/
#include <bits/stdc++.h>
using namespace std;
int	N,B;

void InputData(void){
	cin >> N >> B;
}
void Solve(void){
	int minv, maxv;
	int value = B/(N-1);
	if(B % (N-1)){
		minv = maxv= B + value;
	}else{
		minv = B + value - 1;
		maxv = B + value;
	}
	cout << minv << " "<< maxv;
}
int main(void)
{
	InputData();
	Solve();	
	return 0;
}
/*[실전][4843]할부*/
