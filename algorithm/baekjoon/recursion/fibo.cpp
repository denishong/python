#include<iostream>
using namespace std;
long long d[1000];
int fibo(int a){
	if(a==0) return 0;
	else if(a==1) return 1;

	if(a>=2) return fibo(a-1) + fibo(a-2);
	return 0;
}
int main(){
	int n;
	cin>>n;
	cout<<fibo(n)<<endl;
	return 0;
}
