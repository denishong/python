#include <iostream>
using namespace std;

#define MAXN 100
int paper[MAXN + 10][MAXN + 10]; //도화지 

void FillPaper(int sy, int sx, int ey, int ex){
    for( int i=sy; i<ey; i++){
        for( int j=sx; j<ex; j++){
            paper[i][j] = 1;
        }
    }
}
void InputData(){
    int N,x,y;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> y >> x;
        FillPaper(y, x, y+10, x+10);
    }
}
void Solve(){
    int sum=0;
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            if(paper[i][j] == 0) continue;
            sum++; 
        }
    }
    cout << sum << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
