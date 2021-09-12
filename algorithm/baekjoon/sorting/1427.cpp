/*baekjoon 1427 소트인사이드*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string N;
void InputData(){
    cin >> N;
}
bool comp(string a, string b){ return a < b;}
void Solve(){
    sort(N.rbegin(),N.rend());
    cout << N << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*baekjoon 1427 소트인사이드*/
