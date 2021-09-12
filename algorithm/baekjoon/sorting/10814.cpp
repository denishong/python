/*baekjoon 10814 나이순 정렬*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

struct ST{
	int age;
	char name[110];
};

int	N;
struct ST PersonData[MAX];

void InputData(){
	//input data size
	cin >> N;
	//input data
	for(int i = 0; i < N; i++){
		cin >> PersonData[i].age >> PersonData[i].name;
	}
}

void OutputData(){
	for( int i=0; i<N; i++){
		printf("%d %s", PersonData[i].age, PersonData[i].name);
	printf("\n");
	}
}

bool Comp_age(struct ST i, struct ST j){ return (i.age < j.age);}
bool Comp_name(struct ST i, struct ST j){ return (i.name < j.name);}

int main()
{
	InputData();
	stable_sort( PersonData, PersonData+N, Comp_age);
	OutputData();

	return 0;
}
/*baekjoon 10814 나이순 정렬*/
