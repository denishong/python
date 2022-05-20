#include <iostream>
#include <algorithm>
using namespace std;
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
long long A[MAXNM+10];//잔디 구간 시작
long long B[MAXNM+10];//잔디 구간 끝

struct DATA{
    int s,e;
};

struct DATA data[MAXNM+10];
void InputData(){
    cin >> N >> M;
    for (int i=0 ; i<M ; i++){
        cin >> A[i] >> B[i];
    }
}
bool Comp(struct DATA a, struct DATA b){
    return (a.s < b.s);
}
int isPossible(long long d){
    long long cow=data[0].s;//첫번째 소는 첫번째 잔디구간의 시작위치에 위치함 
    int midx=0; //잔디구간 인텍스 
    for(int i=1; i<N; i++){
        long long ncow=cow+d;
        while((midx<M) && (data[midx].e<ncow)){//ncow(다음소를 놓을 위치)위치가 현재 
            midx++;
        }
        if(midx==M) return 0;
    cow=(ncow<data[midx].s) ? data[midx].s : ncow;
    }
    return 1;//배치 가능 
}
int Solve(){
    for(int i=0; i<M; i++){
        data[i].s=A[i];
        data[i].e=B[i];
    }
    sort(data, data+M,Comp);

    long long sol,s=0, e=data[M-1].e-data[0].s;

    while(s<=e){
        long long m=(s+e)/2;
        if(isPossible(m)){
            sol=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return sol;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans=Solve();

    cout << ans << "\n";// 출력하는 부분
    return 0;
}
