#include <iostream>
using namespace std;
#define MAXP ((int) 1e6)
int N;	// 필터의 수
int R[11]; // 반사의 정도
int P[11]; // 투과의 정도
int sol = 11;
int diff = 0x7FFFFFFF;
int mindiff;
int mincnt=0;

int ABS(int num){
    return (num < 0) ? -num : num;
}
void InputData(void){
    cin >> N;
    for(int i=1; i<=N; i++)  cin >> R[i] >> P[i];
}
void DFS(int s, int cnt, long long mul, long long sum){
    cout << "s: " << s << " ,cnt : " << cnt << " ,mul : " << mul << " ,sum: " << sum;
    if(cnt !=0){
        long long diff = ABS(mul - sum);
        cout << "mindiff : " << mindiff << " diff: " << diff << endl;
        if ((mindiff > diff) ||
            ((mindiff == diff) && (mincnt > cnt ))){
                mindiff = diff;
                mincnt = cnt;
        }
    }
    for(int i = s; i <= N; i++){
        DFS(i+1, cnt+1, mul*R[i], sum+P[i]);
    }
}
void Solve(){
    mindiff = MAXP;
    DFS(1, 0, 1, 0);
    cout << N - mincnt << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
