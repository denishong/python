#include <iostream>
using namespace std;

int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID
int used[10];
int sol;
int sum[10][100000+10];
int cnt[10];

void InputData(){
    int i;
    cin >> N >> M;
    for(i = 1; i <= N; i++){
        cin >> ID[i];
    }
}
void DFS(int n,int p, int m){

    if(sol<=m) return; //가지치기 이미 이전 답보다 좋지않음 
    if(n > M){
        if(sol>m) sol=m;
        return;
    }
    for(int i=1;i<=M; i++){
        if(used[i]) continue; //이미 i번 제품은 정리했음 
        used[i]=1;
        int mcnt=cnt[i]-(sum[i][p+cnt[i]-1] - sum[i][p-1]);
        DFS(n+1,p+cnt[i],m+mcnt);
        used[i]=0;
    }
}
void Solve(){
    sol =N;
    for(int i=1; i<=N; i++){
        sum[ID[i]][i]=1;//각 제ID의 개수 
    }
    for(int j=1; j<=M; j++){
        for(int i=1; i<=N; i++){
        cout << sum[j][i] << ' ';//각 제ID의 개수 
        }
        cout << endl;
    }
    for(int i=1; i<=M; i++){
        for(int j=2; j<=N; j++){
            sum[i][j]+=sum[i][j-1];//각 제ID의 개수 
        }
        cnt[i]=sum[i][N];
    }
    for(int j=1; j<=M; j++){
        for(int i=1; i<=N; i++){
        cout << sum[j][i] << ' ';//각 제ID의 개수 
        }
        cout << endl;
    }
    cout << "sum[i][N]" ;
    for(int i=1; i<=N; i++){
        cout << sum[i][N] << ' ';//각 제ID의 개수 
    }
    cout << endl;
    DFS(1,1,0);//순서 
    cout << sol << endl;
}
int main(){
    InputData();//입력 함수
    Solve();
    return 0;
}
