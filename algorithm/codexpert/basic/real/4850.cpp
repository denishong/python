/*[실전][4850]두 수의 최소합*/
#include <bits/stdc++.h>
using namespace std;

int N;
int A[14 + 10];
void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
}

bool comp(int a, int b){ return a < b;}

int conv(int A[], int cnt){
	int sum=0;	
	for(int i=0; i<cnt; i++){
		sum = sum*10 + A[i];		
	}
	return sum;
}

int Solve(){
	int B[20], C[20];
	int bcnt=0, ccnt=0;
	//1.오름차순 정렬
	sort(A, A+N, comp);
	//2.[0] 또는 [0][1] 0이면 0이 아닌 값과 교체
	if(A[0] == 0){
		int i;
		for(i =1; i<N; i++){
			if(A[i] != 0) break;
		}
			A[0] = A[i];
			A[i] = 0;
		if(A[1] == 0) {
			A[1] = A[i+1];
			A[i+1] = 0;
		}	
	}
	//3. 두개의 숫자 만들기
	for(int i=0; i <N; i++){
		if(i%2) B[bcnt++] = A[i];
		else C[ccnt++] = A[i];
	}	
	//4. 합 리턴
	return conv(B, bcnt) + conv(C, ccnt);
}

int main(){
    int ans = -1;
    InputData();
	ans = Solve();
    cout << ans << endl;
    return 0;
}
/*[실전][4850]두 수의 최소합*/
