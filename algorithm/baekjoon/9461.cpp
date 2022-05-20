/*[9461]파도반 수열*/
#include <bits/stdc++.h>
using namespace std;
int T,N; 
int d[101]={0,1,1,};
int p(int n){
	if(n<3) return d[n];
	else if(d[n]==0) ;
		d[n]=p(n-3)+p(n-2); 
	return d[n];
}
void InputData(){
    cin >> T;
}
void Solve(){
	for(int i=0; i<T; i++){
		cin>>N;
		cout<<p(N);
	}
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[9461]파도반 수열*/
