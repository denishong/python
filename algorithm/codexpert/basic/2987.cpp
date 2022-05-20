/*
농부 John은 최근 소 도서관을 위한 책꽂이를 구매했지만, 책이 빠른 속도로 채워져서 지금은 가장 윗부분에만 공간이 남아있다.
농부 John은 N마리의 소를 가지고 있다.(1 <= N <= 20) 각각의 소의 키는 H_i이다.(1 <= H_i<= 1,000,000)
책꽂이는 B 높이를 가지고 있다. (1 <= B <= S, S는 모든 소의 키의 합계임).
책꽂이의 제일 윗부분에 닿기 위해서, 하나 혹은 여러 마리의 소가 서로의 머리 위에 올라설 수 있다.
그래서 그들의 전체 높이는 개개인 소의 키의 합계가 된다. 
소들이 책꽂이의 제일 윗부분에 닿기 위해서는 이 전체높이가 책꽂이 높이에 비해 낮아서는 안 된다.
소들이 서로의 머리 위에 올라서게 되면, 높으면 높을수록 위험해지기 때문에,
당신이 할 일은 책꽂이의 제일 윗부분에 닿을 수 있게 하는 소들의 키의 합의 최소값을 찾는 것이다.
당신의 프로그램은 당신이 찾게 된 소들의 키의 합이 책꽂이로부터 얼마나 초과하는지를 출력하면 된다.

[입력]
첫 번째 줄에는 테스트케이스의 갯수 T가 입력된다.
두 번째 줄부터 T개의 테스트케이스 세트가 주어진다.
테스트케이스의 첫번째 줄은 소의 마리수 N과 B가 주어진다. (1 <= N <= 20,1 <= B <= S, S는 모든 소의 키의 합계)
테스트케이스의 두번째 줄부터 N줄에 각 소의 키 H_i가 주어진다. (1 <= H_i<= 1,000,000)
[입력예시]
1
5 16
3
1
3
5
6
[출력예시]
1
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN (20)
int N, B;
int H[MAXN + 10];
void InputData(){
    cin >> N >> B;
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
}
bool compare(int a, int b){
    return (a > b);}

void Solve(){
    int min=10000000;
    sort(H,H+N, compare);
    for(int i=0; i<N; i++){
        if(H[i] < B){
            B-=H[i];
        }else if(H[i]==B){
            min=H[N-1];
            break;
        }else{
            if(abs(H[i]-B) <min) min=abs(H[i]-B);
        }
    } 
     cout << min << endl;
}
int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분
        Solve();
    }
    return 0;
}
