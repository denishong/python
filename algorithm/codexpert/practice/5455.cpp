#include <iostream>
using namespace std;

int N;
int sm[100000+10];
int sd[100000+10];
int em[100000+10];
int ed[100000+10];
int flower[1240];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> sm[i] >> sd[i] >> em[i] >> ed[i];
    }
}
int Solve(){
    //1.꽃 정보 저장
    for (int i=0; i<N; i++){
        int d1=sm[i]*100+sd[i];
        int d2=em[i]*100+ed[i];
        if(flower[d1]<d2) flower[d1]=d2;
    }
    int i=101, e=301,cnt=0;
    for(;;){
        int max=0;
        //cout << "i,e,cnt,max:" << i << ' ' << e << ' ' << cnt << ' ' << max << endl;
        while(i<=e){
            if(max<flower[i]) max=flower[i];
            i++;
        }
        if(max<=e) return 0;
        cnt++;
        if(max>1130) return cnt;
        e=max;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;

    InputData();// 입력받는 부분

    ans=Solve();
    cout << ans << "\n";// 출력하는 부분
    return 0;
}
