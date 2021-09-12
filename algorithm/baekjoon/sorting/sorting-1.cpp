/*baekjoon 2750 수 정렬하기*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1001


int	N=5;
int	data[] = {5,2,3,4,1};

void InputData(){
	//input data size

	//input data
}

void OutputData(){
	for( int i=0; i<N; i++)
		printf("%d\n", data[i] );
}

bool comp(int i, int j){ return (i>j);}

int main()
{
	InputData();
	sort(data, data+N,comp);
	OutputData();

	return 0;
}
/*baekjoon 2750 수 정렬하기*/
