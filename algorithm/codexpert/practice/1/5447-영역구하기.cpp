#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];

int sol[MAX * MAX];//각 영역 넓이 저장용
int map[MAX+10][MAX+10];//모눈종이 100x100 
int cnt;
struct Q{
    int y,x;
};
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
queue<Q>q;
bool isInside(int a, int b){
        return ( (b>=0) && (b<N) && (a>=0) && (a<M) ); //범위 채크 
}
void push(int y, int x){
    if(map[y][x]==1) return;
    map[y][x]=1;
    cnt++;
    q.push({y,x});
}
void FloodFillDFS(int y, int x){
    if(!isInside(y,x) || map[y][x]!=0) return;
    map[y][x]=1;
    cnt++;
    for(int i=0; i<4; i++){
        FloodFillDFS(y+dy[i],x+dx[i]);
    }
}
int FloodFillBFS(int y, int x){
    //1.큐 초기화 
    q={};
    //2.초기값 설정 
    q.push({y,x});
    map[y][x]=1;
    cnt++;
    //3.반복문 
    while(!q.empty()){
    Q cur=q.front();
    q.pop();
    for(int i=0; i<4; i++){
        int ny=cur.y+dy[i];
        int nx=cur.x+dx[i];
        if(isInside(ny,nx) && map[ny][nx]==0){
            map[ny][nx]=1;
            cnt++;
            q.push({ny, nx});
        }
    }

    }
    //4.실패 
    return cnt;

}
int Solve(){
    int count=0;
    for(int i=0; i<K; i++){
        for(int y=sy[i]; y<ey[i]; y++){
            for(int x=sx[i]; x<ex[i]; x++){
                map[y][x]=1;
            }
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if( map[i][j]==0){
                cnt=0;
                FloodFillBFS(i,j);
                sol[count++]=cnt;
            }
        }
    }
    sort(sol, sol+count);    
    return count;
}
void InputData(){
    cin >> M >> N >> K;
    for (int i=0; i<K; i++){
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    }
}
void OutputData(int ans){
    cout << ans << "\n";
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력받는 부분

    ans=Solve();//여기서부터 작성

    OutputData(ans);//출력하는 부분
    return 0;
}
