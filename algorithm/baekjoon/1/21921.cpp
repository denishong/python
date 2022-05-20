#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int N,X;
void Solve(){
	queue<int>q;
	unordered_map<int,int>number;
	int cnt=0,sum=0,M=0;
	while(N--){
		int visit;
		cin >> visit;
		sum+=visit;
		q.push(visit);
		cnt++;
	
		if(cnt>=X){
			M=max(M,sum);
			number[sum]++;
			sum-=q.front();
			q.pop();
			cnt--;
		}
	}

	if(M==0){
		cout << "SAD" << endl;
	}else{
		cout <<M<<endl;
		cout<<number[M]<<endl;
	}
}
void InputData(){
	cin >> N >> X;
}
int main(){
	InputData();
	Solve();
	return 0;
}
