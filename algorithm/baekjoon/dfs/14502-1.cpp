#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int map[8][8];
int temp[8][8];

int maxSum = 0;

int n, m;
vector<pair<int, int>> v;

//상하좌우 좌표 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
void spreadVirusBFS(){
    queue<pair<int, int>> q;
    for(int i = 0; i < v.size(); i++)
        q.push(v[i]);
     
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
             //주어진 범위를 벗어나면 무시 
            if(nx >= n || nx <= -1 || ny >= m || ny <= -1)
                continue;

            if(temp[nx][ny] == 0){
                temp[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

// 맵 복사 함수 
void copyMap(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = map[i][j];
        }
    }
}

// 안전 구역 세는 함수 
int countSafeZone(){
    int currentSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(temp[i][j] == 0)
                currentSum += 1;
        }
    }
    
    return currentSum;
}

// 브루트포스 벽 세우기 
void makeWallDFS(int x, int depth){
    if(depth == 3){
        // 모든 조합을 구하기 위해 원본 배열 수정하면 안되므로 복사해서 사용  
        copyMap();
        // 바이러스 퍼트리기 
        spreadVirusBFS();
        // 현재 저장되어 있는 최대값과 비교해서 저장 
        maxSum = max(maxSum, countSafeZone());
        return;
    }
    
    for(int i = x; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){ // 빈공간 일 경우
                    map[i][j] = 1; // 벽 세우기 
                    makeWallDFS(i, depth + 1); // 세운 벽 수 증가 
                    map[i][j] = 0; // 초기화 
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            
            if(map[i][j]==2) 
                v.push_back(make_pair(i, j));
        }
    }
    
    makeWallDFS(0,0);
    cout << maxSum;
}
