#include<iostream>
using namespace std;
long long fac(int a){
	if(a>1) return a*fac(a-1);
	else return 1; 
}
int main(){
	int N;
	cin>>N;
	cout<<fac(N)<<endl;
	return 0;
}
