#include <iostream>
#include <queue>
using namespace std;
int N,M,S;
void InputData(){
    cin >> N >> S >> M;
}
void Solve(){
    queue<int> q;
    int i,j=S;
    for(i=1; i<=N; i++){
        q.push(j); 
        if(++j > N) j=1;
    }
#if 0
    for(i=1; i<=N; i++){
        cout << q.front() << ' '; 
        q.pop();
    }
#endif
    //for(i=1; i<=N; i++){
    while(!q.empty()){
        for(j=1; j<M; j++){
            q.push(q.front());
            //cout << "queue : " << q.front() << ' ';
            q.pop();
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
