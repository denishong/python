#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int N;
int D[MAXN];
int max_sum=(1<<31);
void dfs(int n, int sum){
	if(n>N) return;
	max_sum=max({max_sum,D[n],sum});

	if(D[n]>sum){
		sum=0;
		n--;
	}
	dfs(n+1,sum+D[n+1]);
}
void InputData(){
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>D[i];
}
int main(){
	InputData();
	dfs(1,D[1]);
	cout<<max_sum<<endl;
	return 0;
}
