#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

int N;
int A[100+10];
int B[100+10];
int paper[MAXN+10][MAXN+10];
int dr[] = {-1, 1,0,0};
int dc[] = {0, 0,-1,1};

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
}
void FillPaper(int sr, int sc, int er, int ec){
	for(int i=sr; i<er; i++){
		for(int j=sc; j<ec; j++){
			paper[i][j] = 1;
		}
	}
}
int Check( int r, int c){
	int nr, nc;
	int total =0;	
	for(int i=0; i<4; i++){
	nr = r + dr[i];
	nc = c + dc[i];
	
	if(nr<0 || nc<0 || nr>=MAXN || nc>=MAXN || !paper[nr][nc]) total++;
	}
	return total;
}
int Solve(){
	int sum=0;
	for(int i=0; i<N; i++){
		FillPaper(A[i], B[i],A[i]+10, B[i]+10);
	}	

	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			if(paper[i][j] == 0) continue;
			sum += Check(i,j);
		}
	}
	return sum;
}
int main(){
    int ans = -1;
    InputData();
	ans=Solve();
    cout << ans << endl;
    return 0;
}
