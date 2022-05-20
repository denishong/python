#include <bits/stdc++.h>
using namespace std;
#define MAXN  100
int W, H;
int sw, sh, ew, eh;
char Map[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int dx[] ={-1,1,0,0};
int dy[] ={0,0,1,-1};
bool isInside(int y, int x){
	return ((y>=1) && (y<=H) && (x>=1) && (x<=W));
}
void InputData(){
    cin >> W >> H;
    cin >> sw >> sh >> ew >> eh;
    for (int i=1; i<=H; i++){
        cin >> &Map[i][1];
    }
}
int Solve(void){
	int cur_x, cur_y,next_x,next_y;
	queue <pair<int,int>> q;
	q.push(pair<int,int>(sh,sw));
	visited[sh][sw] = 0;
	while(!q.empty()){
		cur_y=q.front().first;
		cur_x=q.front().second;
		if((cur_y==eh) && (cur_x==ew)) { return visited[cur_y][cur_x];}
		q.pop();
		for(int i=0; i<4; i++){
			next_y= cur_y + dy[i];
			next_x = cur_x + dx[i];
			if(isInside(next_y,next_x) &&  Map[next_y][next_x]!='1' && visited[next_y][next_x]==0){
				visited[next_y][next_x] = visited[cur_y][cur_x] +1;
				q.push(pair<int,int>(next_y,next_x)); 
			}
		}
	}
	return -1;
}
int main(){
	int ans = 0;
    InputData();
	ans=Solve();
    cout << ans << endl;
    return 0;
}
