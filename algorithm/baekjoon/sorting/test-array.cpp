/*baekjoon 10989  수 정렬하기 3*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001

int	N;
int NumData[MAX] = {0}; 

void InputData(){
	int tmp;
	for(int i = 0; i < 10; i++){
		NumData[i]++;
	}
		NumData[5]++;
	for(int i = 0; i < 10; i++){
		cout << NumData[i] << "\n";
	}
}

void OutputData(){
	for( int i=0; i<MAX; i++){
		if(NumData[i]){
			for(int count=0; count<NumData[i]; count++)
				printf("%d\n", i);
		}
	}
}

int main()
{
	InputData();
	//OutputData();

	return 0;
}
/*baekjoon 10989  수 정렬하기 3*/
