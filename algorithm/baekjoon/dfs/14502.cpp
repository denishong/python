#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N,M;//행,열 
int map[8][8];
int tmp[8][8];//방문 표시
int dy[]={-1,1,0,0};//상하좌우
int dx[]={0,0,-1,1};
struct Q{
	int y,x;
};
queue<Q>q;
vector<Q>v;
int sol=0;
bool isInside(int a, int b){
	return ( (a>=0) && (a<N) && (b>=0) && (b<M));
}
int BFS(){	
	int count=0;
	//1.큐 초기화 
	q={};
	//2.큐에 초기값 입력 
    for(int i = 0; i < v.size(); i++)
        q.push(v[i]);
	//3.반복문 
	while(!q.empty()){
		Q cur=q.front();q.pop();
		for(int i=0; i<4; i++){
			int ny=cur.y+dy[i];
			int nx=cur.x+dx[i];
			if(isInside(ny,nx) && tmp[ny][nx]==0){
				tmp[ny][nx]=2;
				q.push({ny,nx});
			}	
		}
	}
	//4.return할 값 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tmp[i][j]==0)
				count++;
		}
	}
	return count;
}
void copymap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			tmp[i][j]=map[i][j];
		}
	}
}
	
void DFS(int x, int d){
	if(d==3){
		copymap();//기존 map을 훼손하면 안되므로 임시 map에 저장함 
		sol=max(sol,BFS());//감염되지 않은 방중 최대값으로 업데이트 
		return;
	}
	for(int i=x; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==0){
				map[i][j]=1;
				DFS(i,d+1);
				map[i][j]=0;
			}
		}
	}

}
void Solve(){
	DFS(0,0);//맵에서 벽을 세울수 있는 경우를 DFS를 이용해서 조합으로 만듬
	cout<<sol<<endl;//오염되지 않은 방중 가장 큰값 
}
void InputData(){
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				v.push_back({i,j});//바이러스 걸린 방을 따로 저장해 두어야한다. 
			}
		}
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
