#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
#define MAX 100010

int main()
{

	stack<int> s;

	int i, n, start=1;
	int dt[MAX];
	char dtout[MAX];
	cin >> n;
	
	for(i= 0; i<n; i++ ){
		cin >> dt[i];
	}

	i = 0;
	int j, k =0, max=0;
	while( dt[i] != 0 ){
		if ( dt[i] > max){
			max = dt[i];
			for(j = start; j <= dt[i]; j++, start++ ){
				s.push( j );
				dtout[k++] = '+';
			}
			if( !s.empty() ){
				dtout[k++] = '-';
				s.pop();
			}
		}
		if( !s.empty() ){
			if( s.top() == dt[i] ){
				dtout[k++] = '-';
				s.pop();
			}else if( s.top() > dt[i] ) {
				dtout[0] = '*';
			}
		}
		i++;
	}

	int size;
	size = strlen( dtout );
	if( dtout[0] == '*' ) {
		cout << "NO" << endl;
	}
	else if( dtout[0] != '*' ){
		for( i = 0; i< size; i++) {
			cout << dtout[i] << endl;
		}
	}

	return 0;
}
