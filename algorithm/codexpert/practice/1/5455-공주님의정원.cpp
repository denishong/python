#include <iostream>
using namespace std;

int N;
int sm[100000+10];
int sd[100000+10];
int em[100000+10];
int ed[100000+10];
int flower[1300];
int Solve(){
	//1.flower배열에 꽃 피워있는 정보표시 
	for (int i=0; i<N; i++){
		int idx=sm[i]*100 + sd[i];//피는 날자 
		int val=em[i]*100 + ed[i];//지는 날자 
		//flower[idx]=val;
		if(flower[idx] < val) flower[idx]=val;
	}
	//2.flower 배열 탐색하며 결과 찾기 
	int i=101, e=301, cnt=0;
	for(;;){
		int max=0;
		while(i<=e){
			if(max<flower[i]) max=flower[i];
			i++;
		}	
		if(max<=e) return 0;//실패 
			cnt++;
		if(max>1130) return cnt;
			e=max;
	}
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> sm[i] >> sd[i] >> em[i] >> ed[i];
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
