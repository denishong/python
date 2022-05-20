#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAXN ((int)3e6)
#define MAXD ((int)3e3)
#define MAXK ((int)3e3)
int N, D, K, C;//접시수, 종류수, 연속해서 먹는 접시의 수, 쿠폰번호
int A[MAXN + MAXK];
int check[MAXN + MAXK];
int flag,coupon;
int Solve(){
    int maxi=0;
    for(int i=0; i<N; i++){
        flag=0;//중복된 스시 채크 
        coupon=1;//쿠폰 스시가 있는 지 확인 
        for(int j=i; j<i+K; j++){
            if(check[A[j%N]] == 1) flag++;//이미 먹은 초밥일 경우 중복 수 표시 
            else check[A[j%N]] = 1 ;//이미 먹은 초밥일 경우 중복 수 표시 

            if(A[j%N]==C) coupon=0; //쿠폰 스시 있을 시
        }
        maxi=max(maxi,K-flag+coupon);
        memset(check,0,sizeof(check)); //채크 초기화 
    }
    return maxi;
}
void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
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
