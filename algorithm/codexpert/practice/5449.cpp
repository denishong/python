#include <iostream>
using namespace std;
#define MAXN ((int)1e5)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];
int CalDist(int a, int b){
    return abs(X[a] - X[b]) + abs(Y[a] - Y[b]);
}
void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> X[i] >> Y[i];
    }
}
int Solve(){
    //1.원래 전체 길이 구하기
    int total = 0;
    for (int i=1; i<N; i++){
        total += CalDist(i, i+1);
    }
	cout << "total:" << total << endl;
    //2.2~N-1 중 건너뛰었을때 최대로 줄일수 있는 값
    int maxv = 0;
    for (int i=2; i<N; i++){//i가 건너뛰는 체크 포인트
        int dist = CalDist(i-1, i) + CalDist(i, i+1) - CalDist(i-1, i+1);
	cout << "dist:" << dist<< endl;
        if (maxv < dist) maxv = dist;
    }
    //3.전체길이 - 최대로 줄일수있는 값 = 답
    return total - maxv;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;

    InputData();//입력받는 부분
    ans=Solve();
    cout << ans << "\n";//출력하는 부분
    return 0;
}
