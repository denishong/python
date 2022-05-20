#include <iostream>
using namespace std;

int y[110];//살균대상의 y 좌표 배열
int x[110];//살균대상의 x 좌표 배열
int N;//필터 한 변의 크기
int L;//LED의 범위(길이) 
int M;//살균대상의 개수
int sol;//정답

void InputData(void){
    cin >> N >> L >> M;
    for (int i = 0; i < M; i++) cin >> y[i] >> x[i];
}
int count(int c, int r, int h, int w){
    int cnt=0;
    for(int i=0; i<M; i++){
        if((c<=y[i]) && (y[i]<=h) && (r<=x[i]) && (x[i]<=w)) cnt++;
    }
    return cnt;
}
void Solve(void){
    int w,offset,maxv=0,cnt,k=L/2;
    for(int h=1; h<k; h++){
        w=k-h;
        for(int offset=0; offset<w; offset++){
            for(int i=0; i<M; i++){
                cnt=count(y[i], x[i]-offset, y[i]+h, x[i]-offset+w);
                if(maxv < cnt) maxv=cnt;
            }
        }
    }
    cout << maxv << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
