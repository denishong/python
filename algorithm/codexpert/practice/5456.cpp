#include <iostream>
using namespace std;
#define MAXN (6)
int K;
int A[MAXN+10];
int B[MAXN+10];
void InputData(){
    cin >> K;
    for (int i=0 ; i<MAXN ; i++){
        cin >> A[i] >> B[i];
    }
}
int Solve(){
	int maxidx=0,area;
	for(int i=1; i<MAXN; i++){
		if(B[maxidx] < B[i]) maxidx=i;
	}
	int n1=(maxidx+1)%6;
	int n2=(maxidx-1+6)%6;
	if(B[n1]<B[n2]){
		area=B[maxidx]*B[n2]-B[(maxidx+2)%6]*B[(maxidx+3)%6];
	}else{
		area=B[maxidx]*B[n1]-B[(maxidx-2+6)%6]*B[(maxidx-3+6)%6];
	}
	return area*K;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
	ans=Solve();
    cout << ans << "\n";// 출력하는 부분
    return 0;
}
