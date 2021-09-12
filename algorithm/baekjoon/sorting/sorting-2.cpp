/*baekjoon 2750 수 정렬하기*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1001

struct ST{
	int id, score;
};

int	N=5;
struct ST	data[] = {{1,5},{2,50},{3,30},{4,15},{5,100}};

void InputData(){
	//input data size

	//input data
}

void OutputData(){
	for( int i=0; i<N; i++){
		printf("%d  %d", data[i].id, data[i].score );
	printf("\n");
	}
}

bool comp(struct ST i, struct ST j){ return (i.score < j.score );}

int main()
{
	InputData();
	sort( data, data+N, comp );
	OutputData();

	return 0;
}
/*baekjoon 2750 수 정렬하기*/
