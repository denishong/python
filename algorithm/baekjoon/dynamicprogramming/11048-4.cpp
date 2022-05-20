#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
int N,M;//가로 세로
int A[MAXN][MAXN];
int D[MAXN][MAXN];

void Solve(void){
  for(int i=1; i<=N;i++){
    for(int j=1; j<=M; j++){
      D[i][j] = max({D[i-1][j],D[i][j-1]}) + A[i][j];
    }
  }
  cout<<D[N][M]<<endl;
}
void InputData(void){
  cin >> N>>M;
  for(int i=1; i<=N;i++){
    for(int j=1; j<=M; j++){
      cin>>A[i][j];
    }
  }
}
int main(void){
  InputData();
  Solve();
  return 0;
}
