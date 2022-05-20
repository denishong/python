#include<iostream>
using namespace std;
long long fibo(int n){
	if(n>=2) return fibo(n-1)+fibo(n-2);
	else if (n==1) return 1; 
	else if (n==0) return 0;
}
int main(){
	int N;
	cin>>N;
	cout<<fibo(N)<<endl;
	return 0;
}
