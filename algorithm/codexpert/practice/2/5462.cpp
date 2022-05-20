#include <iostream>
using namespace std;

int N;
int grids[500+10][500+10];
int visited[500+10][500+10];
int visitedcnt;
int sol;
int dh[]={-1,1,0,0};
int dw[]={0,0,-1,1};
bool FloodFill(int h, int w, int d, int half){
	visited[h][w]=d;//방문표시 
	if(++visitedcnt>=half) return true;//이미 절반 이상 방문 가능해서 성공
	for(int i=0; i<4; i++){
		int nh=h+dh[i];
		int nw=w+dw[i];
		if( (nh<0) || (nh>=N) || (nw<0) || (nw>=N) ) continue;
		if(visited[nh][nw]==d) continue;
		if(abs(grids[nh][nw] -grids[h][w])>d) continue;
		if(FloodFill(nh,nw,d,half)) return true;//성공 리턴되면 true return
	}
	return false;
}
bool isPossible(int d){
	int sum=0, half=(N*N)/2;

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if( visited[i][j]==d ) continue; 
			visitedcnt=0;
			FloodFill(i,j,d, half);
			if(visitedcnt >= half) return true;
				sum+=visitedcnt;
			if(sum>half) return false;
		}
	}
	return false;
}
int Solve(){
	//1.높이중 최대,최소값 	
	sol=0;
	int minv=(int)2e6,maxv=-1;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if( grids[i][j] < minv) minv=grids[i][j];
			if( grids[i][j] > maxv) maxv=grids[i][j];
		}
	}
	//2.이진탐색하여 가능한(D) 값 중 최소값 
	int s=0, e=maxv-minv, sol=e;
	while(s<=e){
		int m=(s+e)/2;
		if(isPossible(m)){
			sol=m;
			e=m-1;
		}else{
			s=m+1;
		}
	}
	return sol;
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin >> grids[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	InputData();// 입력받는 부분
	ans=Solve();// 여기서부터 작성
	cout <<  ans << "\n";// 출력하는 부분
	return 0;
}
