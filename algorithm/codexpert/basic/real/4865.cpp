#include <iostream>
using namespace std;

#define MAXN 100
int paper[MAXN + 10][MAXN + 10]; //도화지 

void FillPaper(int sr, int sc, int er, int ec){
    for( int i=sr; i<er; i++){
        for( int j=sc; j<ec; j++){
            paper[i][j] = 1;
        }
    }
}
void InputData(){
    int N,sc,sr;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> sc >> sr;
        FillPaper(sr, sc, sr+10, sc+10);
    }
}
void PrintData(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            cout << paper[i][j];
        }
        cout << endl;
    }
}
int Check(int r, int c){
    int cnt=0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for ( int i=0; i<4; i++){
        int nr = r+dr[i];
        int nc = c+dc[i];
        if ((nr<0) || (nr>=MAXN) || (nc<0) || (nc>=MAXN) || !paper[nr][nc] ) cnt++;
    } 
    return cnt;
}
int Solve(){
    int sum=0;
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            if(paper[i][j] == 0) continue;
            sum += Check(i,j);
        }
    }
    return sum;
}
int main(){
    int ans;
    InputData();
    PrintData();
    ans = Solve();
    cout << ans;
    return 0;
}
