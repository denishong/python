#include <iostream>
#include <string.h>
using namespace std;
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
//방문표시 
//[빨간세로][빨간가로][파란세로][파란가로]
int visited[MAXN+5][MAXN+5][MAXN+5][MAXN+5];
typedef struct{
    int rh,rw,bh,bw,t;//빨간세로,가로,파란세로,가로,기울임횟수 
}QUE;
QUE que[MAXN*MAXN*MAXN*MAXN+10];
int wp,rp;
int rsh,rsw,bsh,bsw;
void push(int rh, int rw, int bh, int bw,int t){
    if(visited[rh][rw][bh][bw]==1) return; //이미방문함 
    visited[rh][rw][bh][bw]=1; //방문표시  
    que[wp].rh=rh;que[wp].rw=rw;que[wp].bh=bh;que[wp].bw=bw;que[wp].t=t;wp++;
}
void pop(){rp++;}
QUE front(){return que[rp];}
int empty(){return rp==wp;}

int BFS(){
    int r,c;
    int dh[]={-1,1,0,0};
    int dw[]={0,0,-1,1};
    //1.큐의 초기화,visted배열 초기화 
    rp=wp=0;
    memset(visited, 0,sizeof(visited));
    //2.시작위치를 큐에 넣기(빨간구슬,파란구슬의 위치를 찾아서 큐에 넣기)
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(map[r][c]=='R'){
                rsh=r; rsw=c;
                break;
            }
        }
    }
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(map[r][c]=='B'){
                bsh=r; bsw=c;
                break;
            }
        }
    }
    push(rsh,rsw,bsh,bsw,0);
    //3.큐에서 꺼내서 반복 탐색 
    while(!empty()){
        QUE cur=front(); pop();
        //10회까지만 시도 
        if(cur.t>=10) break;
        for(int i=0; i<4; i++){
            int rnh=cur.rh+dh[i];
            int rnw=cur.rw+dw[i];
            int bnh=cur.bh+dh[i];
            int bnw=cur.bw+dw[i];
            //빨간 구슬j벽채크 
            if(map[rnh][rnw]=='#'){
                rnh=cur.rh;rnw=cur.rw;//원래자리로 
            }
            //파란 구슬 벽체크 
            if(map[bnh][bnw]=='#'){
                bnh=cur.bh;bnw=cur.bw;//원래자리로 
            }
            //구슬이 부딪혀서 깨짐 
            if((rnh==bnh) && (rnw==bnw)) continue;
            //파란 구슬이 H에 들어감 
            if(map[bnh][bnw]=='H') continue;
            //빨간구슬에 H에 들어감 
            if(map[rnh][rnw]=='H') return cur.t+1;
            push(rnh,rnw,bnh,bnw,cur.t+1);
        }
    }
    //4.실패 리턴 
    return -1;
}
void InputData(){
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> map[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, ans=-10;
    cin >> T;
    for (int i=0; i<T; i++){
        InputData();//입력

        ans=BFS();//여기서부터 작성

        cout << ans << "\n";//출력
    }
    return 0;
}
