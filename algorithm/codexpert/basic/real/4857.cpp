/*[4857][실전] 택배*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)2e3)
#define MAXC ((int)1e4)
#define MAXM ((int)1e4)
int N, C, M;
struct DATA{
	int s,e,cnt;
};
DATA A[MAXM + 10];
int truck[MAXN + 10];
void InputData(void){
    cin >> N >> C;
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> A[i].s >> A[i].e >> A[i].cnt;
    }
}
bool comp(struct DATA a, struct DATA b){ return a.e < b.e;}
int Solve(void){
	int sum=0;
	sort(A, A+M, comp);
	for(int i=0; i<M; i++){
		int maxv = 0;
		//1.s~(e-1) truck 값 중에 최대값 구하기 
		for( int k=A[i].s; k<A[i].e; k++){
			if(maxv < truck[k]) maxv = truck[k];
            cout <<__func__ << __LINE__ << "maxv, truck[k]:" << maxv<<' '<<truck[k] << endl;
		}
		maxv = C - maxv;//싣을 수 있는 최대값 = 트럭 총 용량 - 이미 실려 있는 용량 
		if( maxv > A[i].cnt) maxv = A[i].cnt;
		//3.정보 갱신 
		sum += maxv;
		for( int k =A[i].s; k<A[i].e; k++){
			truck[k] += maxv;
		}
	}
	return sum;
}
int main(void){
    int ans = -1;
    InputData();
	ans = Solve();
    cout << ans << endl;
    return 0;
}
/*[4857][실전] 택배*/
