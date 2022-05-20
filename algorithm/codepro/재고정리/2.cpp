#include <stdio.h>

int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID
int seq[10];
int used[10];
int sol;
int count[10];//각 제품 ID의 수 

void InputData(){
    int i;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++){
        scanf("%d", &ID[i]);
    }
}

int check(int p, int id){
    int cnt=0;
    int i,j,k;
    for( k=0; k< count[id]; k++){
        if(ID[p+k] != id) cnt++;
    }
    return cnt;
}
void DFS(int n,int p, int m){
    int cnt;
    
    if(sol<=m) return; //가지치기 이미 이전 답보다 좋지않음 
    if(n > M){
        if(sol>m) sol=m;
        return;
    }
    for(int i=1;i<=M; i++){
        if(used[i]) continue; //이미 i번 제품은 정리했음 
        used[i]=1;
        cnt =check(p,i);
        seq[n]=i;
        DFS(n+1,p+count[i],m+cnt);
        used[i]=0;
    }
}
void Solve(){
    sol =N;
    for(int i=1; i<=N; i++){
        count[ID[i]]++;//각 제ID의 개수 
    }
    DFS(1,1,0);//순서 
    printf("%d\n",sol);
}
int main(){
    InputData();//입력 함수
    Solve();
    return 0;
}

