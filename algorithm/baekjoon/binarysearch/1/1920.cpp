#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN (int)1e6
int N,M;
int A[MAXN],B[MAXN];
bool BSearch(int n){
	int s=0, e=N-1;
	int sol;
	while(s<=e){
		int m=(s+e)/2;
		if(A[m]==n){
			return true;
		}else if(A[m]>n){
			e=m-1;
		}else{
			s=m+1;
		}
	}	
	return false;
}
void Solve(){
	sort(A,A+N);
	for(int i=0; i<M; i++)
		printf("%d\n",BSearch(B[i]));
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
