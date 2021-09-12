#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX ((int)2e5) 

int N; 
int A[MAX+10]; 
int M; 
int B[MAX+10]; 
int Temp[MAX+10];
void InputData() { 
	cin >> N;
	for(int i=0 ; i<N ; i++) { 
		cin >> A[i]; 
	} 
	cin >>  M;
	for(int i=0 ; i<M ; i++) { 
		cin >> B[i]; 
	} 
} 
void OutputData() { 
	for(int i=0 ; i<M ; i++) { 
		cout <<  B[i] << " "; 
	} 
	cout << endl;
}  
int BinarySearchLower(int s, int e, int d){
    int m, sol = -1;
    while( s <= e) {
        m = (s+e) /2;
        if( A[m] == d){
            sol = m;
            e = m -1;
        }
        else if (A[m] > d) e = m -1;
        else s = m+1;
    }
    return sol;
}

int BinarySearchUpper(int s, int e, int d){
    int m, sol = -1;
    while( s <= e) {
        m = (s+e) /2;
        if( A[m] == d){
            sol = m;
            s = m +1;
        }
        else if (A[m] > d) e = m -1;
        else s = m + 1;
    }
    return sol;
}

void Solve(){
	for(int i=0 ; i<M ; i++) { 
        int lower = BinarySearchLower(0, N-1, B[i] );
        //cout << "lower: " << lower << endl;
    if ( lower != -1 ){
        int upper = BinarySearchUpper(0, N-1, B[i] );
        //cout << "upper: " << upper << endl;
		B[i] = upper - lower + 1; 
	} 
     else  B[i] = 0; 
	} 
    
}
int main(void) { 
	InputData(); 
    Solve();
	OutputData(); 
	return 0; 
} 
