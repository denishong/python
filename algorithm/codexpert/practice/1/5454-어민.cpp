#include <iostream>
using namespace std;
int N;//마을 수
int A[100000+10];//마을 위치
int B[100000+10];//잡힌 물고기 양
long long sol;
#define s64 long long
int isPossible(int m){
	s64 need=0;
	for(int i=0; i<N-1; i++){
		need=need+B[i]-m;
		if(need<0) {//부족한 경우 
			need-=A[i+1]-A[i];
		}else{
			need-=A[i+1]-A[i];
			if(need<0) need=0;
		}
	}
	return (need+B[N-1]-m)>=0;
}
int Solve(){
	int s=0,e=0,sol=1;
	for(int i=0; i<N; i++){
		if(e<B[i]) e=B[i];
	}
	while(s<=e){
		int m=(s+e)/2;
		if(isPossible(m)){
			sol=m;
			s=m+1;
		}else{
			e=m-1;
		}
	}
	return sol;
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i] >> B[i];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	ans=Solve();//여기서부터 작성

	cout << ans << "\n";//출력하는 부분
	return 0;
}
