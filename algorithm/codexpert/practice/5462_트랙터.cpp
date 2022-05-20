#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int N;
int grids[500+10][500+10];
int visited[500+10][500+10];
int area; //방문한 영역의 크기 
int half; //들판 면적의 절반 
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int FloodFill(int r, int c, int d){
    visited[r][c]=d;//방문표시
    
    area++;//영역 크기 증가 
    if(area>=half) return 1;//이미 half 이상의 크기이므로 더이상 탐색필요없음 
    for(int i=0; i<4; i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        //범위 채크
        if((nr<0) || (nr>=N) || (nc<0) || (nc>=N)) continue;
        //방문 채크 
        if(visited[nr][nc]==d) continue;
        //D로 갈수 있는지 채크
        if(abs(grids[r][c]-grids[nr][nc])>d) continue;
        if(FloodFill(nr,nc,d)==1) return 1;
    }
    return 0;
}
int isPossible(int d){
    //visited 배열 초기화(->대신에 d값으로 visited에 표시) 
    //memset(visited,0,sizeof(visited));
    int sum=0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(visited[i][j]==d) continue;//이미 방문했음 
            area=0;
            FloodFill(i,j,d);
            if(area>=half) return 1;//들판의 절반 이상을 돌아다닐 수 있음 
            sum+=area;
            if(sum >half) return 0;//실패한 영역의 합이 절반이상(남은 영역의 크기가 절반도 되지않아서 실패)
        }
    }
    return 0;
}
int Solve(){
    int max=-1,min=(int)1e6 +10;
    half=(N%2==1) ? (N*N/2+1) : (N*N/2);
    //이진 탐색의 s,e를 입력된 높이중 min,max로 
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(max < grids[i][j]) max = grids[i][j];
            if(min > grids[i][j]) min = grids[i][j];
        }
    }
    //이진탐색 lower bound
    int s=min, e=max-min, sol=e;
    while(s<=e){
        int m=(s+e)/2;
        if(isPossible(m)){
			cout << "success :m:" << m << endl;
            sol=m;
            e=m-1;
        }else{
			cout << "fail : m:" << m << endl;
            s=m+1;
        }

    }
    return sol;
}
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> grids[i][j];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;

    InputData();// 입력받는 부분

    ans=Solve();// 여기서부터 작성

    cout <<  ans << "\n";// 출력하는 부분
    return 0;
}
