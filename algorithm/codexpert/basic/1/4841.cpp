#include <bits/stdc++.h>
using namespace std;
#define MAXN (100)
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부
void InputData(){
    cin >> K;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> Z[i];
    }
}
int Solve(){
	int bomb=0;	
	for(int i=0; i<N; i++){
		bomb += T[i];
		if(bomb > 210) break;
		if(Z[i] == 'T'){ //정답인 경우 
			if(++K>8) K=1;	
		
	}
	return K;
}
int main(){
    int ans = -1;
    InputData();//입력받는 부분
	ans = Solve();
    cout << ans << endl;//출력하는 부분
    return 0;
}
