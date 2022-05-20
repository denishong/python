#include <iostream>
using namespace std;
#define MAXN 100
int N;//색종이 수
int X[100+10];
int Y[100+10];
int paper[100+10][100+10];
void FillPaper(int y, int x){
    for(int i=y; i<y+10; i++){
        for(int j=x; j<x+10; j++){
            paper[i][j]=1;
        }
    }
}
int isPossible(int sh, int sw, int eh, int ew){
    for(int i=sh; i<=eh; i++){
        for(int j=sw; j<=ew; j++){
            if(paper[i][j]==0) return 0;
        }
    }
    return 1;
}

int Solve(){
    int maxarea=100, area=0;
    for(int i=0; i<N; i++){
        FillPaper(Y[i],X[i]);
    }
    for(int sh=0; sh<MAXN; sh++){ //좌상단 세로 좌표 
        for(int sw=0; sw<MAXN; sw++){//좌상단 가로 좌표 
            if(paper[sh][sw] == 0) continue;//색종이 안 붙어 있으면 
            for(int eh=sh+1; eh<MAXN; eh++){//우하단 세로 좌표 
                for(int ew=sw+1; ew<MAXN; ew++){//우하단가로 좌표  
                    if(paper[eh][ew]==0) break;
                    area=(eh-sh+1) *(ew-sw+1);
                    if(maxarea>=area) continue;
                    if(isPossible(sh,sw,eh,ew)==0)  break;
                    //cout << "area:" << area;
                    maxarea=area;
                }
            }
        }
    }
    return maxarea;
}
void InputData() {
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력받는 부분

    ans=Solve();//여기서부터 작성

    cout << ans << "\n";//출력하는 부분
    return 0;
}
