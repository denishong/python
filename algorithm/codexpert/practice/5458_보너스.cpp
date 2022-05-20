#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN (10)
#define MAXM (100)
int N, M;//직원수, 상하관계개수
int s[MAXM+1];
int e[MAXM+1];
int bonus[MAXN+1];//보너스금액
int sol[MAXN+1];//실제지불
bool used[MAXN+1];//보너스금액 지불 여부
bool link[MAXN+1][MAXN+1];//[상급자][하급자]=여부(1:YES, 0:NO)
bool isPossible(int n, int p){
    for (int i=1; i<=N; i++){//직원 인덱스
        if (n == i) continue;//본인임
        if (sol[i] == 0) continue;//판단불가, i번 직원은 아직 지급 전
			cout << "n,i,link[n][i], sol[i], p :" <<n<<' '<< i << ' '<<link[n][i] << ' ' << sol[i] << ' ' << p << endl;
        if ((link[n][i]) && (sol[i] >= p)) return false;//n번 직원이 하급자 보다 많지 않음. 불가
        if ((link[i][n]) && (sol[i] <= p)) return false;//n번 직원이 상급자 보다 적지 않음. 불가
    }
    return true;//가능
}
bool DFS(int n){//직원 인덱스
    if (n > N) return true;//모든 직원에게 보너스 위배 없이 지불, 성공
    for (int i=2; i<=N; i++){//보너스 인덱스
        if (used[i]) continue;//i번 금액은 이미 지불 되었음
        if (!isPossible(n, bonus[i])) continue;//n번 직원에게 i번 금액 지불 불가
        used[i]=true;//사용표시
        sol[n]=bonus[i];//n번 직원에게 i금액 지불함
        if (DFS(n+1)) return true;//성공했으면 리턴
        used[i]=false;//표시제거
        sol[n]=0;//
    }
    return false;//실패
}
bool comp(int a, int b){
    return a > b;
}
void Solve(){
    //0.link 배열에 관계 표시
    for (int i=0; i<M; i++){
        link[s[i]][e[i]]=true;
    }
    //1.bonus배열 내림차순 정렬
    sort(&bonus[1], &bonus[N+1], comp);
    //2.1번이 사장이므로 제일 큰 금액
    sol[1] = bonus[1];
    //2.2번 직원부터 모든경우(순열)
    DFS(2);
}
void InputData(){
	cin >> N >> M;
	for (int i=0; i<M; i++){
		cin >> s[i] >> e[i];
	}
	for (int i=1; i<=N; i++){
		cin >> bonus[i];
	}
}
void OutputData(){
	for (int i=1; i<=N; i++){
		cout << sol[i] << " ";
	}
	cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력받는 부분
	Solve();// 여기서부터 작성
	OutputData();// 출력하는 부분
	return 0;
}
