#include <iostream>
using namespace std;
#define MAX ((int)2e5)

int N;
int A[MAX+10];
int M;
int B[MAX+10];
int BinarySearchUpper(int s, int e, int d){
	int sol=-1;
	while(s<=e){
		int m=(s+e)/2;
		if(A[m]==d){
			sol=m;
			s=m+1;
		}else if(A[m]>d){
			e=m-1;
		}else{
			s=m+1;
		}
	}
	return sol;	
}
int BinarySearchLower(int s, int e, int d){
	int sol=-1;
	while(s<=e){
		int m=(s+e)/2;
		if(A[m]==d){
			sol=m;
			e=m-1;
		}else if(A[m]>d){
			e=m-1;
		}else{
			s=m+1;
		}
	}
	return sol;	
}
void Solve(){
	int upper, lower;
	for(int i=0; i<M; i++){
		lower=BinarySearchLower(0,N-1,B[i]);
		if(lower!=-1){
			upper=BinarySearchUpper(0,N-1,B[i]);
			B[i]=upper-lower+1;
		}
		else{
			B[i]=0;
		}
	}
}
void InputData(){
    cin >> N;
    for(int i=0 ; i<N ; i++) {
        cin >> A[i];
    }
    cin >> M;
    for(int i=0 ; i<M ; i++) {
        cin >> B[i];
    }
}

void OutputData(){
    for(int i=0 ; i<M ; i++) {
        cout << B[i] << " ";
    }
    cout << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력받는 부분
    InputData();

    Solve();// 여기서부터 작성


    // 출력하는 부분
    OutputData();
    return 0;
}
