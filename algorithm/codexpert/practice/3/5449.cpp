#include <iostream>
using namespace std;
#define MAXN ((int)1e5)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];
int CalcDist(int a, int b){
	return abs(X[a]-X[b]) + abs(Y[a]-Y[b]);
}
int Solve(){
	int total=0,dist=0,max=0;
	for(int i=0; i<N-1; i++)
		total+=CalcDist(i,i+1);

	for(int i=1; i<N-2; i++){
		dist=CalcDist(i-1,i) + CalcDist(i,i+1) - CalcDist(i-1,i+1);
		if(dist>max) max=dist;
	}
	return total-max;
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> X[i] >> Y[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	InputData();//입력받는 부분
	ans=Solve();//여기서부터 작성
	cout << ans << "\n";//출력하는 부분
	return 0;
}
