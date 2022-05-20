#include <iostream>
using namespace std;
#define MAXN (100)
int N;
int K;
int R[MAXN+10];
int C[MAXN+10];
int L;
int X[MAXN+10];
char CMD[MAXN+10];
int map[MAXN+10][MAXN+10];//게임격자 0:빈곳,1:뱀,2:과일 
int order[10000+10];//[초] + 방향'L': 1 , 'D': 0 
typedef struct{
    int r,c;//가로,세로 
}QUE;
QUE que[10000+10];
int wp,rp;
void push(int r, int c){
    map[r][c]=1;
    que[wp].r=r;que[wp].c=c; wp++;
}
void pop(){rp++;};
QUE front(){return que[rp];}
int empty(){return rp==wp;}
int Solve(){
    //'L' 기준:우상좌하 
    int dr[]={0,-1,0,1};
    int dc[]={1,0,-1,0};

    //게임 격자에 과일표시 
    for(int i=0; i<K; i++){
        map[R[i]][C[i]]=2;
    }
    //해당 초의 방향 정보 표시 
    for(int i=0; i<L; i++){
        order[X[i]]= (CMD[i]=='L') ? 1:-1;
    }

    push(1,1);//뱀의 시작위치 
	map[1][1]=1;
    int head_r,head_c,head_dir;//뱀의 머리위치와 방향 
    for(int t=0; ; t++){
        head_dir=(head_dir+order[t] + 4) %4;//order[t]:t초후의 방향 
        head_r+=dr[head_dir];//t+1초의 뱀머리 좌표 
        head_c+=dc[head_dir];//t+1초의 뱀머리 좌표 
        //범위 채크(벽에 부딪힘)
        if((head_r<1) ||(head_r>N)||(head_c<1)||(head_c>N)) return t+1;
        //몸과 충돌 
        if(map[head_r][head_c]==2) return t+1;
        //과일이 없는 경우라면 꼬리 제거 
        if(map[head_r][head_c]==0){
            QUE tail=front();
            pop();
            map[tail.r][tail.c]=0;//꼬리제거 
        }
        push(head_r, head_c);
        map[head_r][head_c]=2;
    }
}
void InputData(){
    cin >> N;
    cin >> K;
    for (int i=0; i<K; i++){
        cin >> R[i] >> C[i];
    }
    cin >> L;
    for (int i=0; i<L; i++){
        cin >> X[i] >> CMD[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;

    InputData();//입력받는 부분

    ans=Solve();//여기서부터 작성

    cout << ans << "\n";//출력하는 부분
    return 0;
}
