#include <iostream>
using namespace std;

int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID
int seq[10];
int used[10];
int sol;
int count[10];//각 제품 ID의 수 

int check(void){
    int cnt=0;
    int i,j,k;
    for( i=1, j=1; i<=M; i++){
        for( k=0; k< count[seq[i]]; k++){
        if(ID[j++] != seq[i]) cnt++;
        }
    }
    cout << "cnt:" << cnt << endl;
    return cnt;
}
void DFS(int n){
    int cnt;
    if(n > M){
        cnt =check();
        if(sol>cnt) sol=cnt;
        return;
    }

    for(int i=1;i<=M; i++){
        if(used[i]) continue; //이미 i번 제품은 정리했음 
        used[i]=1;
        seq[n]=i;
        DFS(n+1);
        used[i]=0;
    }
}
void Solve(){
    sol =N;
    for(int i=1; i<=N; i++){
        count[ID[i]]++;//각 제ID의 개수 
    }
    DFS(1);//순서 
    cout << sol << endl;
}
void InputData(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> ID[i];
    }
}

int main(){
    InputData();
    Solve();
    return 0;
}
