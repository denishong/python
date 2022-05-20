#include <iostream>
using namespace std;
#define MAXM (7)
int N;//임의의수
int WV[2][MAXM+1];
int A;//하나당 추가 가치

int sol;//가장 가치가 높은 수식의 수식 가치
int solcnt[MAXM+1];//사용횟수
int value;
int chk[MAXM];
int set[]={1,2,4,8,16,32,64};
int s[MAXM];
int checkHang(){
    int ret=0;
    for(int i=0; i<MAXM; i++){
        ret+=chk[i];
    }
    return ret;
}
void DFS(int n, int sum){
    //1.가지치기 
    if(sum>N) return;

    //종료조건 
    if(sum==N){
        value=0;
        for(int k=0; k<MAXM; k++){
            if(chk[k]>=5) value+=(chk[k]*WV[1][k]);
            else value +=(chk[k]*WV[0][k]);
        }
        value+=(A*checkHang());
        if(value>sol){
            sol=value;
            for(int l=0; l<MAXM; l++) s[l]=chk[l];
        }
        return;
    }
    for(int i=n; i<MAXM; i++){
        chk[i]++;
        DFS(i,sum+set[i]);
        chk[i]--;
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
        cout << s[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();//입력

    DFS(0,0);//여기서부터 작성

    OutputData();//출력
    return 0;
}
