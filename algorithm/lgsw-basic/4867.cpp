/*[4867][10과-도형기하격자]원안의 사각형*/
#include <bits/stdc++.h>
using namespace std;
int R;
void InputData(void){
	cin >> R;
}
void Solve(){
	int cnt=0;
	for(int a=1; a<=R; a++){
		for(int b=1; b<=R; b++){
			if(a*a + b*b <= R*R){
				cnt++;
			}
		}
	}
	cout << cnt*4 << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
/*[4867][10과-도형기하격자]원안의 사각형*/
