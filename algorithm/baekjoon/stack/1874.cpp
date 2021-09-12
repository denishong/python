#include <iostream>
#include <stack>

using namespace std;
#define MAX 100010

int main()
{

	stack<int> s;

	int i, n, start=1;
	int dt[MAX];
	cin >> n;
	
	for(i= 0; i<n; i++ ){
		cin >> dt[i];
	}

	i = 0;
	int j, max=0;
	while( dt[i] != 0 ){
		if ( dt[i] > max){
			max = dt[i];
			if( dt[i] > start ){
				for(j = start; j <= dt[i]; j++, start++ ){
					s.push( j );
					cout << '+' << endl;
				}
				if( !s.empty() ){
					cout << '-' << endl;
					s.pop();
				}
			}
		}
		if( s.top() == dt[i] ){
			if( !s.empty() ){
				cout <<  '-' << endl;
				s.pop();
			}
		}
		i++;
	}

	return 0;
}
