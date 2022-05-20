#include <iostream>
#include <stack>
using namespace std;
#define MAXN ((int) 1e5+10)
int N;
int H[MAXN];
void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];
}
void Solve(void){
    int totalcnt = 0;
    stack <int> s;
    for( int i =0; i<N; i++ ){
        while( !s.empty() && ( s.top() < H[i])){
            totalcnt++;
            cout << "s.top() : " << s.top() << " H[i] : " << H[i] << " totalcnt : " << totalcnt  << " line : " <<  __LINE__ << endl;
            s.pop();
        }
        if ( !s.empty() ){
            totalcnt++;
            cout << "s.top() : " << s.top() << " H[i] : " << H[i] << " totalcnt : " << totalcnt  << " line : " <<  __LINE__ << endl;
            if( s.top() == H[i]) s.pop();
        }
        s.push(H[i]);
    }
    cout << totalcnt << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
