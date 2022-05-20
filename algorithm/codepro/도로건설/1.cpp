#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e2 + 10)

int N;//지도 크기
char mmap[MAXN][MAXN];//지도 정보
#define IMP (1<<29)
int visited[MAXN][MAXN]={0,};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
bool isInside(int y, int x){
    return ((x>=0)&&(x<N)&&(y>=0)&&(y<N));
}
void InputData(){
  cin >> N;
  for (int i = 0; i < N; i++){
      cin >> mmap[i];
  }
}
void OutputData(){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cout << visited[i][j];
    }
    cout << endl;
  }
}

int BFS(){
  queue<pair<int,int>> q;
  int y=0,x=0;
  q.push(pair<int, int>(y, x));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      visited[i][j] = IMP;
    }
  }
  visited[0][0]=0;
  while(!q.empty()){
    y = q.front().first;
    x = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(isInside(ny,nx) && visited[ny][nx] > visited[y][x]+mmap[ny][nx]-'0'){
        visited[ny][nx] = visited[y][x] + mmap[ny][nx]-'0';
        q.push(pair<int,int>(ny,nx));
      }
    }
  }
  return visited[N-1][N-1];
}

int main(){
  InputData();
  cout << BFS() << endl;
  return 0;
}
