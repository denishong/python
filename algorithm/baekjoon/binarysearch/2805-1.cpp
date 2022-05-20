#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN (int)1e6 + 10
int H[MAXN];
int N,M;
void Solve(){
    int s,e;
	int m,sum=0,sol=0;
	sort(H,H+N);
    s=1; e=H[N-1];
	while(s<=e){
		sum=0;
		m=(s+e)/2;
		for(int i=0; i<N; i++){
			if(H[i]>=m) sum+=H[i]-m;	
		}
		if(sum >= M){
			sol=m;
			s=m+1;
		}else if(sum < M){
			e=m-1;
		}
	}
	cout << sol << endl;
}
void InputData(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> H[i];
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
