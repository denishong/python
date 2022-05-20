#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int N;
int D[MAXN];
void Solve(){
	int sol=-300000, sum=0;
	for(int i=0; i<N; i++){
		if(sum>0)
			sum+=D[i];
		else
			sum=D[i];
		
	if(sum>sol) sol=sum;
	}
	cout<<sol<<endl;
}
void InputData(){
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>D[i];
}
int main(){
	InputData();
	Solve();
	return 0;
}
