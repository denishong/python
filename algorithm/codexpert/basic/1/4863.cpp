#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e4)
int K;
int A[MAXN+10];//방향 
int B[MAXN+10]; //길이 
void InputData(){
	cin >> K;
	for(int i=0; i<6; i++){
		cin >> A[i] >> B[i];
	}	
}
void Solve(){
	int maxidx=0,area=0;
	for(int i=1; i<MAXN; i++){
		if(B[maxidx] < B[i] ) maxidx=i;
	}
	//2.이웃한 두 변의 인덱스 구하기
	int x = (maxidx+1)%6;
	int y = (maxidx-1+6)%6;
	//3.어떤 유형인지 판단 
	if( B[x] < B[y] ){
		area = B[maxidx]*B[y] - B[(maxidx+2)%6]*B[(maxidx+3)%6];
	}else{
		area = B[maxidx]*B[x] - B[(maxidx-2+6)%6]*B[(maxidx-3+6)%6];
	}	
	cout << area*K;
}
int main(){
	InputData();
	Solve();
	return 0;
}
