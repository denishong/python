#include <iostream>
#include <stack>

using namespace std;

#define MAX 1000000
int dt[MAX]; 	// input data
int rlt[MAX];	// dt[i]의 오큰수는 rlt[i]에 저장 

int main()
{
	int n=0,i,j=0;
	int min =0;

	cin >> n ;

	stack<int> stkNotFound; 	//오큰수를 아직 찾지 못한 수들 
	stack<int> stkNotFoundIdx;	//오큰수를 아직 찾지 못한 수들의 인덱스 

	for(int i =0; i < n; i++){
		cin >> dt[i];
	}

	for(int i =0; i < n; i++){
		int idx = i;
		cout << "stkNotFound.size : " << stkNotFound.size() << endl;
		//cout << "stkNotFound.top: " << stkNotFound.top() << endl;
	
		while (( stkNotFound.size() > 0 ) && ( stkNotFound.top() < dt[idx] )) {
			rlt[stkNotFoundIdx.top()] = dt[idx];
			stkNotFound.pop();
			stkNotFoundIdx.pop();
		}

		stkNotFound.push(dt[idx]);
		stkNotFoundIdx.push(idx);
			
	}

	while(stkNotFoundIdx.size() > 0 ){
		rlt[stkNotFoundIdx.top()] = -1;
		stkNotFoundIdx.pop();
	}


	//마지막 수의 오큰수는 항상 -1
	rlt[n-1] = -1;


	for( int i =0; i < n; i++) {
		cout << rlt[i] << ' ';
	}

	return 0;
}
