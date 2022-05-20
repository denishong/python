/*[baekjoon]2447 별 찍기-10*/
#include <bits/stdc++.h>
using namespace std;
int N;
void star(int x, int y){
    while (x != 0) {
        if (x % 3 == 1 && y % 3 == 1) {
            cout <<" ";
            return;
        }
        x /= 3;
        y /= 3;
    }
    cout << "*";
    return;
}
void Solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            star(i,j);
        }
        cout << endl;
    }
}
void InputData(){
    cin >> N;
}
int main()
{
    InputData();
    Solve();
    return 0;
}
/*[baekjoon]2447 별 찍기-10*/
