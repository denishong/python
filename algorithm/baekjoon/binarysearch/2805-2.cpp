#include<iostream>
using namespace std;
#define MAXN ((int) 1e6+10)
int N,M;
int D[MAXN];
long long Check(long long a){
	long long sum=0;
	for(int i=0; i<N; i++){
		if(D[i]>a)
			sum+=D[i]-a;
	}
	return sum;
}
void Solve(){
	long long s,e,mid,sol=0;
	s=1, e=(int)2e9;	
	while(s<=e){
		mid=(s+e)/2;
		if(Check(mid)>=M){
			sol=mid;
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	cout<<sol<<endl;
}
void InputData(){
	cin>>N>>M;
	for(int i=0; i<N; i++)
		cin>>D[i];
}
int main(){
	InputData();
	Solve();
	return 0;
}
