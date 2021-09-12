/*baekjoon 1874*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
#define MAX 100001
int dt[MAX];
char dtout[MAX];
stack<int> s;


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
        dtout[k++] = '+';
        while( !s.empty() && s.top() == dt[j] ){
            s.pop();
            dtout[k++] = '-';
            j++;
        }
    }

    size = strlen( dtout );
    if( !s.empty() ) {
        printf("NO");
        return 0;
    }else{
        for( i = 0; i< size; i++) {
            printf("%c\n", dtout[i]);
        }
    }

	return 0;
}
