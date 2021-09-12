#include <iostream>

using namespace std;
int X;
void InputData(){
	cin >> X;
}
void Solve(){
	int cnt=0;	
	for(int i=1; i<1000; i++){
		for(int j=1,k=0; j<=i; j++,k++){
			cnt++;
			if(cnt == X)
				cout << i-k << "/" << j << endl;
		}
	}
}

int main(){
	InputData();
	Solve();
	return 0;
}
