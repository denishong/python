/*baekjoon 10989  수 정렬하기 3*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10000000

int	N;
int Data[MAXN+10]; 
void OutputData(){
	for(int i = 0; i < N; i++){
		printf("%d\n", Data[i]);
	}
}

void InputData(){
	//input data size
	cin >> N;
	//input data
	for(int i = 0; i < N; i++){
		Data[i];
	}
}

void Solve(){
    sort(Data, Data+N);
	for( int i=0; i<N; i++){
		printf("%d\n", Data[i]);
	}
}

int main()
{
	InputData();
    OutputData();
	//Solve();
	return 0;
}
/*baekjoon 10989  수 정렬하기 3*/
