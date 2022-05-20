/*[baekjoon]2580번 스도쿠*/
#include <iostream>
#include <vector>
using namespace std;
#define MAX 9 
#define MAXN 10 
int zerocnt;
int map[MAXN][MAXN];
vector <pair<int,int>> v;
bool checkWidth(int y, int x, int value) {
	for (int i = 0; i < 9; i++) {
		if (map[y][i] == value) return false;
	}
	return true;
}

bool checkHeight(int y, int x, int value) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == value) return false;
	}
	return true;
}

bool checkSquare(int y, int x, int value) {
	int startY = y - y % 3;
	int startX = x - x % 3;
	for (int i = startY; i < startY + 3; i++) {
		for (int j = startX; j < startX + 3; j++) {
			if (map[i][j] == value) return false;
		}
	}
	return true;
}
void OutputData(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cout << map[i][j] << ' ';
        }
    cout << endl;
    }
}

void DFS( int cnt){
    if(cnt == zerocnt){
        OutputData();
        exit(0);
    }
    int y = v[cnt].first;
    int x = v[cnt].second;


    for(int i=1; i<=MAX; i++){
        if(checkWidth(y,x,i)==true && checkHeight(y,x,i)==true && checkSquare(y,x,i) == true) {
            map[y][x] = i;
            cout << "map[" << y << "]" << "[" << x << "]:" << map[y][x] << endl;
            DFS(cnt+1);
            map[y][x] = 0;
            cout << "map[" << y << "]" << "[" << x << "]:" << map[y][x] << endl;
        }
    }
}
void Solve(){
    DFS(0);
}

void InputData(){
    int x;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin >> x;
            if( x == 0){
                v.push_back({i,j});
                zerocnt++;
            }else{
                map[i][j] = x;
            }
        }
    }
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon]2580번 스도쿠*/
