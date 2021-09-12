/*baekjoon 5430 dequeue*/
#include <iostream>
#include <deque>
#include <cstring>
#include <stdlib.h>

using namespace std;
deque<char> q;
#define MAX 100 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int i=0,j=0,k=0,l,m;
    int testN; //test case
    int N; // N  
    int K; //K 
    char dt[MAX];
    char control[MAX];
    int numN= 0; 
    int numC, sizeq;
	int flag=true;
    cin >> testN;


    for(i =0; i < testN; i++) {
        cin >> control;
        cin >> N;
        cin >> dt;

		numN = strlen(dt);
		flag = true;
		for(j=0; j<numN; j++) {
			if( dt[j] != '[' && dt[j] != ']' && dt[j] != ',' ) {
				q.push_back(dt[j]);
			}
		}    

		numC = strlen(control);
		for(k=0; k< numC; k++ ) {
			if( control[k] == 'R') {
				flag =! flag;
			} else if (control[k] == 'D' ){
				if(!q.empty()){
					if( flag == true )
						q.pop_front();
					else 
						q.pop_back();
				} else{
					cout << "error" << endl;
					break;
				}
			}
		}

		cout << '[';
		sizeq = q.size();
		for(m=0; m<sizeq; m++){
			if( flag == true ){
				if( q.size() > 1){
				cout << q.front() << ',';
				}else{
				cout << q.front();
				}
				q.pop_front();
			}else if( flag == false ) {
				if( q.size() > 1){
				cout << q.back() << ',';
				}else{
				cout << q.back();
				}
				q.pop_back();
			}
		}
		cout << ']' << endl;

	}


    return 0;
}
