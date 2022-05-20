#include <iostream>
using namespace std;
#define MAXN ((int)15e5+10)
int d[MAXN];
int t[MAXN];
int p[MAXN];
int N;
int check_cnt=0;
void InputData(){
    cin >> N;
	for(int i=0; i<N; i++)
		cin>>t[i]>>p[i];
}
void Solve(){
	for(int i=0; i<N; i++){
		d[i+t[i]]=max(d[i+t[i]], d[i]+p[i]);
		d[i+1]=max(d[i+1], d[i]);
	}

	for(int i=0; i<N; i++)
		cout<<"d[i]:"<<d[i]<<endl;

	cout<<d[N]<<'\n';
}
int main(){
   InputData();
   Solve();
   return 0;
}
