#include <iostream>
using namespace std;

#define MAXN 13
int N;
int chess[MAXN+5][MAXN+5];
int sol =0;

int Check(int y, int x){
    int i,j;
    for( i=0; i<y; i++){
        if(chess[i][x] == 1) return 0;
    }
    for( i=y-1, j=x+1; ((i>=0) && (j<N)); i--, j++){
        if(chess[i][j] == 1) return 0;
    }
    for( i=y-1, j=x+1; ((i>=0) && (j<N)); i--, j++){
        if(chess[i][j] == 1) return 0;
    }
}

void N_Queen(int y){
    int j;
    if( y >=N ){ sol++; return;}
    for( j=0; j<N; j++){
        if(Check(y,j) == 1){
            chess[y][j] = 1;
            N_Queen(y+1);
            chess[y][j]=0;
        }
    }
}

void InputData(){
	cin >> N;
}

int main(){
	int ans = 0;

	InputData();// 입력받는 부분

	// 여기서부터 작성
    N_Queen(0);
    ans = sol;
	cout << ans << endl;// 출력하는 부분

	return 0;
}
