#include <iostream>
#include <vector>
using namespace std;
#define MAXN (int)1e5+10
int N,M;
int A[MAXN];
int Sum[MAXN];
struct V{
	int s,e;
};
vector<V>v;
void Solve(){
	for(int i=0; i<M; i++){
		cout<<Sum[v[i].e]-Sum[v[i].s-1]<<"\n";
	}
}
void InputData(){
	int s,e;
	cin>>N>>M;
	for(int i=1; i<=N; i++){
		cin >>A[i];
		Sum[i]=Sum[i-1]+A[i];
	}
	for(int i=0; i<M; i++){
		cin>>s>>e;
		v.push_back({s,e});
	}
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	InputData();
	Solve();
	return 0;
}
