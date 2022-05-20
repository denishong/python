#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s, e;
};
DATA A[MAXN + 10];
DATA B[MAXN + 10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}
int comp(DATA a, DATA b){
	return(a.e<b.e);
}
int Solve(){
	int j=0;
	int cnt=0;
	//1.1시간 미만인 영화 제거 
    for (int i=0; i<N; i++){
        if((A[i].e - A[i].s)>=2){
			B[j++]=A[i];
		}
    }
	//2.시작시간기준으로 오름차순으로 정렬
	sort(B,B+j,comp);
	int e=B[0].e;	
	cnt++;
    for (int i=1; i<j; i++){
		if( B[i].s >= e){
			cnt++;
			e=B[i].e;
		} 
	}
	return cnt;
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
