#include <iostream>
using namespace std;

#define MAX 4

int Stack[MAX];
int Sp = MAX;
int N;
int A[20+10];

int Push(int d){
	// 여기서부터 작성
    if( Sp == 0){
        return -1;
    } else{
        Stack[--Sp] = d;
        return 1;
    }
}

int Pop(){
	// 여기서부터 작성
     if( Sp == MAX){
        return -1;
    } else{
        return Stack[Sp++];
    }

}

void InputData(){
	cin >> N;
	for(int i=0; i<N; i++) cin >> A[i];
}

void Solve(){
	for(int i=0; i<N; i++){
		if(A[i] > 0){
			int r=Push(A[i]);
			if(r == -1) cout << "-1 ";
		}
		else{
			int r=Pop();
			if(r == -1) cout << "-1 ";
			else cout << r << " ";
		}
	}
}

int main(){
	InputData();
	Solve();
	return 0;
}
