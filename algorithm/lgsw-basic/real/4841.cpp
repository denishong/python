#include <iostream>
using namespace std;
#define MAXN 100

int K;
int N; //퀴즈 개수
int T[MAXN +10]; //걸린 시간 
char Z[MAXN+10]; //정답 여부 

void InputData(void){
	int i;
	cin >> K;
	cin >> N; 
	for(i=0; i<N; i++){
		cin >> T[i] >> Z[i];
	}

}

int Solve(){
	int i, t=0;
	for(i=0; i<N; i++){
		t += T[i];
		if(t > 210 ) break; //폭탄 터짐
		if(Z[i] == 'T'){ //정답인 경우
			if( ++K > 8 ) K =1;
		}  
	}
	return K;
}


int main(void){
	int ans;
	InputData();
	ans = Solve();
	cout << ans << endl;

	return 0;
}
