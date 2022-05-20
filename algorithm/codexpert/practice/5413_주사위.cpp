#include <iostream>
using namespace std;
int N;//던진횟수
int M;//출력모양
 
int num[10];
void DFS1(int n){
    if (n >= N){
        for (int i=0; i<N; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=1; i<=6; i++){
		cout << "n,i:" << n << ' ' << i << endl;
        num[n]=i;
        DFS1(n+1);
    }
}
 
void DFS2(int n, int s){
    if (n >= N){
        for (int i=0; i<N; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=s; i<=6; i++){
        num[n]=i;
        DFS2(n+1, i);
    }
}
 
bool used[10];
void DFS3(int n){
    if (n >= N){
        for (int i=0; i<N; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=1; i<=6; i++){
        if (used[i]) continue;
        used[i]=true;
        num[n]=i;
        DFS3(n+1);
        used[i]=false;
    }
}
 
void Solve(){
    if (M == 1){
        DFS1(0);
    }
    else if(M == 2){
        DFS2(0, 1);
    }
    else{
        DFS3(0);
    }
}
 
void InputData(){
    cin >> N >> M;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();//입력
 
    Solve();//여기서부터 작성
 
    return 0;
}
