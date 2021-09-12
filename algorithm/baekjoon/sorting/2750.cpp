/*baekjoon 2750 수 정렬하기*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1001

int	N;
int	Data[MAXN+10]; 

void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> Data[i];
	}
}
void Solve(){
	for(int i=0; i<N; i++){
		cout << Data[i] << endl;
	}
}
int main()
{
	InputData();
	sort(Data, Data+N);
	Solve();
	return 0;
}
/*baekjoon 2750 수 정렬하기*/
