/*baekjoon 2750 수 정렬하기*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1001

struct ST{
	int age;
	char name[100];
};

int	N=3;
struct ST data[] = {{21,"Junkyu"},{21,"Dohyun"},{20,"Sunyoung"}};

void InputData(){
	//input data size

	//input data
}

void OutputData(){
	for( int i=0; i<N; i++){
		printf("%d  %s", data[i].age, data[i].name);
	printf("\n");
	}
}

bool comp(struct ST i, struct ST j){ return (i.age< j.age);}

int main()
{
	InputData();
	sort( data, data+N, comp );
	OutputData();

	return 0;
}
/*baekjoon 2750 수 정렬하기*/
