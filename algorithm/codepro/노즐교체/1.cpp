#include <iostream>
#include <algorithm>
using namespace std;

int N;// 장비에 장착된 노즐의 가로, 세로 개수
int A[1000][1000];// 각 노즐의 오염도 정보
long long sol;// 정답

void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}
void Solve(){
    long long h=0;
    long long v=0;
    long long sum[2];
    for(int y=0; y<N; y++){
        sum[0]=sum[1]=0;
        for(int x=0;x<N; x++){
            sum[x%2] += A[y][x];
            cout <<"colume A[y][x] :" << A[y][x] << ' ';
        }
        cout << endl << sum[0] << ' ' << sum[1] << endl;
        h+=max(sum[0],sum[1]);
    }

    for(int x=0; x<N; x++){
        sum[0]=sum[1]=0;
        for(int y=0;y<N; y++){
            sum[y%2] += A[y][x];
            cout <<"row A[y][x] :" << A[y][x] << ' ';
        }
        cout << endl << sum[0] << ' ' << sum[1] << endl;
        v+=max(sum[0],sum[1]);
    }
    cout << max(h,v) << endl;
}

int main() {
    InputData();
    Solve();
    return 0;
}
