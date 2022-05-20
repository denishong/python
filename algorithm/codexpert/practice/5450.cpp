#include <iostream>
using namespace std;
#define MAXN 100
int N;//색종이 수
int X[100+10];
int Y[100+10];
int paper[100+10][100+10];
void InputData() {
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}
void FillPaper(int sx, int sy, int ex, int ey){
    for(int i=sy; i<ey; i++){
        for(int j=sx; j<ex; j++){
            paper[i][j]=1;
        }
    }
}
int isPossible(int sy, int sx, int ey, int ex){
    for(int i=sy; i<=ey; i++){
        for(int j=sx; j<=ex; j++){
            if(paper[i][j]==0) return 0;
        }
    }
    return 1;
}
int SolveN6(){
    int maxarea=100, area;
    for(int i=0; i<N; i++){
        FillPaper(X[i],Y[i],X[i]+10,Y[i]+10);        
    }

    for(int sy=0; sy<100; sy++){
        for(int sx=0; sx<100; sx++){
            if(paper[sy][sx]==0) continue;
            for(int ey=sy+1; ey<100; ey++){
                for(int ex=sx+1; ex<100; ex++){
                    if(paper[ey][ex]==0) break;
                    area=(ex-sx+1) *(ey-sy+1);
                    if(maxarea>=area) continue;
                    if(isPossible(sy,sx,ey,ex)==0) break;
                    maxarea=area;
                }
            }
        }
    }
    return maxarea;
        
}
int SolveN3(){
    int maxarea=100, area;
    //0.도화지에 색종이 표시
    for (int i=0; i<N; i++){
        FillPaper(Y[i], X[i], Y[i]+10, X[i]+10);
    }
    //1.배열 정리해서 높이 구하기
    for (int w=0; w<MAXN; w++){//가로
        for (int h=1; h<MAXN; h++){//세로
            if (paper[h][w] == 0) continue;
            paper[h][w] += paper[h-1][w];
        }
    }
    //2.최대넓이 구하기
    for (int r=1; r<MAXN; r++){
        for (int s=0; s<MAXN; s++){
            int h=101;//최소 높이 선택해야 하므로 최대값
            for (int k=s; k<MAXN; k++){
                if (h > paper[r][k]) h = paper[r][k];//낮은 높이 선택
                if (h == 0) break;
                area = h * (k - s + 1);
                if (maxarea < area) maxarea = area;
            }
        }
    }
    return maxarea;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력받는 부분

    ans=SolveN3();
    cout << ans << "\n";//출력하는 부분
    return 0;
}
