#include <iostream>
using namespace std;
#define MAXM (7)
int N;//임의의수
int WV[2][MAXM+1];
int A;//하나당 추가 가치

int sol;//가장 가치가 높은 수식의 수식 가치
int solcnt[MAXM+1];//사용횟수
int twopower[]={1,2,4,8,16,32,64};
int cnt[MAXM];
void DFS(int n, int val, int p){//2의제곱수,N(만들수), 가치 
    //1.가지치기 
	cout << "n,val,p:" << n << ' ' << val << ' ' << p <<  endl;
    if(val==0){
		if(sol<p){
			sol=p;
			for(int i=0; i<MAXM; i++){
				cout << "p,i,cnt[i]:" << p << ' ' << i << ' ' << cnt[i] << endl;
				solcnt[i]=cnt[i];
			}
		}
		return;
	}
	if(n>=MAXM) return; //남은 2의 제곱수없음 
	if(val < twopower[n]) return; //남은 2의 제곱수가 만들수보다 큼
    for(int i=val/twopower[n]; i>=0; i--){//n번째 2의 제곱수 사용 개수 
        cnt[n]=i;
		//cout << "i,val,n,twopower[n]:" << i << ' ' << val << ' ' << n << ' ' << twopower[n] << endl;
        DFS(n+1,val-twopower[n]*i, p+(WV[i>4][n]+A)*i);
        cnt[n]=0;
    }

}
void InputData(){
    cin >> N;
    for (int i=0; i<2; i++){
        for (int j=0; j<MAXM; j++){
            cin >> WV[i][j];
        }
    }
    cin >> A;
}
void OutputData(){
    cout << sol << "\n";
    for (int i=0; i<MAXM; i++){
        cout << solcnt[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();//입력

    DFS(0,N,0);//여기서부터 작성

    OutputData();//출력
    return 0;
}
