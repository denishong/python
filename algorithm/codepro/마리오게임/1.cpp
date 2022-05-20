#include <iostream>
using namespace std;

int N;//버섯 수
int P[150000 + 10];//버섯 값

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }
}
void solve(){
    int sum = P[0];
    for(int i = 1; i < N; i++){
       //cout << "i ,P[i-1] , P[i] " << i << ' ' << P[i-1] << ' ' << P[i] << endl;
        if(P[i - 1] < P[i]){
         sum = sum - P[i - 1] + P[i];
         cout << "i ,P[i-1] , P[i], sum  " << i << ' ' << P[i-1] << ' ' << P[i] << ' ' << sum <<  endl;
        }
    }
    cout << sum;
}
int main(){
    InputData();
    solve();
	return 0;
}
