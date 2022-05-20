#include <stdio.h>
#include <string.h>
#define MAXN ((int)3e6)
#define MAXD ((int)3e3)
#define MAXK ((int)3e3)
int N, D, K, C;//접시수, 종류수, 연속해서 먹는 접시의 수, 쿠폰번호
int A[MAXN + MAXK];
int check[MAXN + MAXK];
int flag,coupon;
int Solve(){
    int varcnt=1,sol=0;
	check[C]=1;
	//1.처음 K개를 먹는 경우 
    for(int i=0; i<K; i++){
		if(check[A[i]]++==0) varcnt++; //0이었으므로 새로운 초밥을 먹음 
		A[N+i]=A[i];
	}
	sol=varcnt;
	for(int i=K; i<N+K-1; i++){
		if(--check[A[i-K]]==0) varcnt--;
		if(check[A[i]]++ ==0) varcnt++;
        if(sol<varcnt) sol=varcnt;
    }   
    return sol;
}

void InputData(void){
    scanf("%d %d %d %d", &N, &D, &K, &C);
    for (int i=0; i<N ; i++){
        scanf("%d", &A[i]);
    }
}

int main(void){
    int ans = -1;

    InputData();// 입력받는 부분

    ans=Solve();// 여기서부터 작성

    printf("%d\n", ans);// 출력하는 부분
    return 0;
}
