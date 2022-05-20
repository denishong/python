#include <iostream>
using namespace std;
#define MAXN ((int)3e6)
#define MAXD ((int)3e3)
#define MAXK ((int)3e3)
int N, D, K, C;//접시수, 종류수, 연속해서 먹는 접시의 수, 쿠폰번호
int A[MAXN + MAXK];
int check[MAXN + MAXK];
void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}
int Solve(){
	int sol=0,varcnt=1;//쿠폰은 먹은 것으로 먼저 계산하자 
	check[C]=1;
	//1.K개 먹은 경우 
	for(int i=0; i<K; i++){
		if(check[A[i]]++==0) varcnt++;	//먹은 초밥이 새로운 경우 
		A[N+i]=A[i]; //%연산을 하지 않도록 뒤에 추가해준다 
	}
	sol=varcnt;
	//2.그 이후 먹는 경우 
	for(int i=K; i<N+K-1; i++){
		if(--check[A[i-K]]==0) varcnt--;//
		if(check[A[i]]++==0) varcnt++;
		if(sol<varcnt) sol=varcnt;
	}
	return sol;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int ans = -1;
    InputData();// 입력받는 부분
    ans=Solve();// 여기서부터 작성
    cout << ans << "\n";// 출력하는 부분
    return 0;
}
