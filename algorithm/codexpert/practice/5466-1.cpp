#include <iostream>
#include <string.h>
using namespace std;
#define MAXH (12)
#define MAXW (6)
char map[MAXH+2][MAXW+2];
 
int visited[MAXH+2][MAXW+2];
int count;
int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};
void CountFloodFill(int h, int w, char color){
    if (map[h][w] != color) return;
    if (visited[h][w] == 1) return;
    count++;
    visited[h][w]=1;
    for (int i=0; i<4; i++){
        CountFloodFill(h+dh[i], w+dw[i], color);
    }
}
void EraseFloodFill(int h, int w, char color){
    if (map[h][w] != color) return;
    map[h][w]='.';
    for (int i=0; i<4; i++){
        EraseFloodFill(h+dh[i], w+dw[i], color);
    }
}
int ErasePuyo(){
    int flag=0;
    for (int h=1; h<=MAXH; h++){
        for (int w=1; w<=MAXW; w++){
            if (map[h][w] == '.') continue;
            if (visited[h][w] == 1) continue;
            count = 0;
            CountFloodFill(h, w, map[h][w]);//같은 뿌요 개수 파악
            if (count < 4) continue;
            EraseFloodFill(h, w, map[h][w]);//제거
            flag=1;
        }
    }
    return flag;
}
void DownPuyo(){
    int puyo;
    for (int w=1; w<=MAXW; w++){
        for (int space=MAXH; space>0; space--){
            if (map[space][w] != '.') continue;
            for (puyo=space-1; (puyo>0) && (map[puyo][w]=='.');puyo--){
				//cout << "space, puyo,w:" << space << ' ' << puyo << ' ' <<w<< endl;
			}
            if (puyo <= 0) break;
            map[space][w] = map[puyo][w];
            map[puyo][w] = '.';
			//cout << "space,w, map[space][w]:" << space << ' ' << w << ' ' <<map[space][w] <<  endl;
			//cout << "puyo,w, map[puyo][w]:" << puyo << ' ' << w << ' '  << ' ' << map[puyo][w] << endl;
        }
    }
}
int Solve(){
    int combo=0;
    for (;;){
        //1.visited 배열 초기화
        memset(visited, 0, sizeof(visited));
        //2.같은색 뿌요가 4개 이상 모여있는 것들 모두 제거(제거한거 없으면 정지)
        if (ErasePuyo() == 0) break;
        combo++;
        //3.게임판 정리, 중력방향으로 떨어트리기
        DownPuyo();
    }
    return combo;
}
 
void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, t, ans = -1;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분
 
        ans = Solve();//여기서부터 작성
 
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}
