#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;//개수
int F[MAXN + 10];
int Blower(int s, int e, int d){
	int sol=e;
	while(s<=e){
		int m=(s+e)/2;
		if(F[m]>=d){
			sol=m;
			e=m-1;
		}else{
			s=m+1;
		}
	}
	return sol;
}
long long Solve(){
	long long sum=0;
	//1.정렬 
	sort(F,F+N);
	//2.이분탐색으로 검색 
	for (int i=1; i<N; i++){
		int min=((F[i]*9+10-1)/10);
		int idx=Blower(0,i,min);
		sum+=i-idx;
	}
	return sum;
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> F[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long ans = -1;
	InputData();// 입력받는 부분
	ans=Solve();// 여기서부터 작성
	cout << ans << "\n";// 출력하는 부분
	return 0;
}
