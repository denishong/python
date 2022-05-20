#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN (int)1e6
int N,M;
int A[MAXN],B[MAXN];
int BSearchUpper(int n){
	int s=0, e=N-1;
	int sol=-1;
	while(s<=e){
		int m=(s+e)/2;
		if(A[m]==n){
			sol=m;
			s=m+1;
		}else if(A[m]>n){
			e=m-1;
		}else{
			s=m+1;
		}
	}	
	return sol;
}

int BSearchLower(int n){
	int s=0, e=N-1;
	int sol=-1;
	while(s<=e){
		int m=(s+e)/2;
		if(A[m]==n){
			sol=m;
			e=m-1;
		}else if(A[m]>n){
			e=m-1;
		}else{
			s=m+1;
		}
	}	
	return sol;
}
void Solve(){
	int lower,upper;
	sort(A,A+N);
	for(int i=0; i<M; i++){
		lower=BSearchLower(B[i]);
		//cout << "B[i],lower:"<<B[i]<<' '<<lower<<endl;
		if(lower!=-1){
			upper=BSearchUpper(B[i]);
			//cout << "upper:"<<upper<<endl;
			printf("%d ", upper-lower+1);
		}else{
			printf("0 ");
		}
	}
}
void InputData(){
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>A[i];
	cin>>M;
	for(int i=0; i<M; i++)
		cin>>B[i];
}
int main(){
	InputData();
	Solve();
	return 0;
}
