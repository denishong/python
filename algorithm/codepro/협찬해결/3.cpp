#include <iostream>
using namespace std;

int N;//협찬 물품의 수
int D[100000 + 10];//선호도
int sol = -30001;//첫번째 방법의 최대 선호도

void InputData(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> D[i];
    }
}
void Solve()
{
    int i, sum = 0;
    for (int i = 0; i < N; i++) {
        if (sum > 0) sum += D[i];
        else sum = D[i];
    cout << "sum, sol:" << sum << ' ' << sol << endl;
    if(sum > sol) sol = sum;
    }
    cout << sol << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
