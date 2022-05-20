#include <iostream>
#include <queue>
using namespace std;
int N,M,S;
void InputData(){
    cin >> N >> S >> M;
}
void Solve(){
    queue<int>q;
    int j=S;
    for(int i=1; i<=N; i++){
        q.push(j); if(++j > N) j=1;
    }
    for(int i=1; i<=N; i++){
        for(j=1; j<M; j++){
            q.push(q.front());q.pop();
        }
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
