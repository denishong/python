#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
#define MAX 100001
int dt[MAX];
stack<int> s;
vector<char> v;

int main()
{
	int i,j=0,k=0, n;
	int size;

	/* input size*/
	cin >> n;
	
	/* input data*/
	for(i= 0; i<n; i++ ){
		cin >> dt[i];
	}

	for( i=1; i <= n; i++){
		s.push(i);
		v.push_back('+');
		while( !s.empty() && s.top() == dt[j] ){
			s.pop();
			v.push_back('-');
			j++;
		}
	}

	if( !s.empty() ) {
		printf("NO");
		return 0;
	}else{
		for( i = 0; i< v.size(); i++) {
			printf("%c\n", v[i]);
		}
	}

	return 0;
}
