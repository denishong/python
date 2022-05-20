#include <iostream>
using namespace std;
#define MAXN ((int)1e5)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];
int CalcDist(int a, int b){
	return (abs(X[a]-X[b]) + abs(Y[a]-Y[b]));
}
int SolveN2(){
	int minv=(int)1e9;

	for(int s=2; s<N; s++){
		int sum=0; //거리합 
		for(int i=1; i<N; i++){
			if(s==i) continue;
			if(s==i+1) sum+=CalcDist(i,i+2);
			else sum+=CalcDist(i,i+1);
		}
		if(minv > sum) minv=sum;
	}
	return minv;
}
int Solve(){
	int maxv=0;
	int total=0;
	for(int i=1; i<N; i++){
		total+=CalcDist(i,i+1);
	}
	for(int i=1; i<N; i++){
		int dist=CalcDist(i,i+1) + CalcDist(i+1,i+2) - CalcDist(i,i+2);
		cout << "Calc1, Calc2, Calc3:" << CalcDist(i,i+1)<< ' ' << CalcDist(i+1,i+2)<< ' '<< CalcDist(i,i+2) <<endl;
		if(maxv < dist) maxv=dist;
	}
	return total-maxv;
}
void InputData(){
	cin >> N;
	for (int i=1; i<=N; i++){
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
