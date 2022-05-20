/*baekjoon 1931 회의실 배정 */
#include <iostream>
#include <queue>
using namespace std;
int N;
queue<pair<int,int>>q;
void InputData(){
    int s,e;
    cin >> N;
    for( int i =0; i < N; i++){
        cin >> s >> e;
        q.push(pair<int,int>(s,e));
    }
}
void Solve(){
    int count=0, tmp =0;
    for(int i=0; i< N; i++ ){
        if( q.front().first == q.front().second ){
            count++;
            q.pop();
            if( tmp == 0 ){
                tmp = q.front().second;
                count++;
                q.pop();
            }
        }else{
            if( q.front().first >= tmp ){
                count++;
                tmp = q.front().second;
                q.pop();
            }else if(q.front().first < tmp ){
                q.pop();
            }
        }
    }
    cout << count << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*baekjoon 1931 회의실 배정 */
