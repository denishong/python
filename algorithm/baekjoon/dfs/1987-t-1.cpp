#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 20;
typedef struct{
    int y, x;

}Dir;
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;
int result;
string board[MAX];
int visited[100];
void DFS(int y, int x, int cnt){
        visited[board[y][x] - 'A']=1; //이미 밟은 알파벳 표시
        for (int i = 0; i < 4; i++)        {
                 int nextY = y + moveDir[i].y;
                 int nextX = x + moveDir[i].x;
                 if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C) //범위 내에 있고
                         if (visited[board[nextY][nextX] - 'A']==0) //새로운 알파벳일 경우에만
                                 DFS(nextY, nextX, cnt + 1); //DFS
        }
        result = max(result, cnt);
}
int main(void){
    cin >> R >> C;
    for (int i = 0; i < R; i++)
         cin >> board[i];

    result = -1;
    DFS(0, 0, 1); //알파벳 A(0) ~ Z(25)
    cout << result << endl;
    return 0;
}
