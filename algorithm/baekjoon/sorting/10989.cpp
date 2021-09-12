/*baekjoon 10989  수 정렬하기 3*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10000000

int	N;
int NumData[MAXN+10]; 

void InputData(){
	int tmp=0;
	//input data size
	cin >> N;
	//input data
	for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
		NumData[tmp]++;
	}
}

void Solve(){
	for( int i=0; i<N; i++){
		if(NumData[i]){
			for(int count=0; count<NumData[i]; count++)
				printf("%d\n", i);
		}
	}
}

int main()
{
	InputData();
	Solve();

	return 0;
}
/*baekjoon 10989  수 정렬하기 3*/
