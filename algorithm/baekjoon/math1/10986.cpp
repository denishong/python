#include <iostream>
using namespace std;

int N,M,x;
long long cnt[1001];
long long sum,ans;
void Solve(){
	cin>>N>>M;
	for(int i=0; i<N; i++){
		cin>>x;
		sum+=x;
		cnt[sum%M]++;
	}
	for(int i=0; i<=1000; i++){
		ans+=cnt[i]*(cnt[i]-1)/2;
	}
	cout << cnt[0]+ans << endl;
}

int main(){
	Solve();
	return 0;
}
