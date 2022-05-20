#include <bits/stdc++.h>
using namespace std;
int N;//보내려는 물품 개수
int C[10];//BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 순)
int sol[10];//보내는 BOX 개수
int num[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 };

int Solve(){
    int sum = 0, i, cnt, totalcnt = 0;
    for(i = 0; i < 10; i++){
        sum += num[i] * C[i];
    }
    sum -= N;

    for(i = 9; i >= 0; i--){
        cnt = sum / num[i];
        if(cnt > C[i]) cnt = C[i];
        sum -= num[i] * cnt;
        sol[i] = C[i] - cnt;
        totalcnt += sol[i];
    }
    return totalcnt;
}
void InputData(){
    cin >> N;
    for(int i = 0; i < 10; i++){
        cin >> C[i];
    }
}
void OutputData(int ans){
    cout << ans << endl;
    for(int i = 0; i < 10; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}
int main(){
    int ans = -1;
    InputData();
    ans = Solve();
    OutputData(ans);
    return 0;
}
