/*[4863][실전]참외 밭(중등)*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e4)
struct Coordinate{
	int d;
	int length;
};
struct ST{
	int x;
	int y;
};
int	N;
struct Coordinate C[MAXN];
struct ST CD[MAXN];
void InputData(){
	cin >> N;
	for(int i = 0; i < 6; i++){
		cin >> C[i].d >> C[i].length;
	}
}
void ChangeCoord(void){
	CD[0].x = 0;
	CD[0].y = 0;

	for(int i=0; i<6; i++){
		if( C[i].d == 1){
			CD[i+1].x = CD[i].x - C[i].length;
			CD[i+1].y += CD[i].y;
		}else if( C[i].d ==2 ){
			CD[i+1].x = CD[i].x + C[i].length;
			CD[i+1].y += CD[i].y;
		}else if( C[i].d == 3){
			CD[i+1].x += CD[i].x;
			CD[i+1].y = CD[i].y - C[i].length;
		}else if( C[i].d == 4){
			CD[i+1].x += CD[i].x;
			CD[i+1].y = CD[i].y + C[i].length;
		}
	}
}
int Solve(void){
	int Sum=0;
	ChangeCoord();	
	for(int i=0; i<6; i++){
		int idx;
		idx = (i+1) % 6;
		Sum += (CD[i].x * CD[idx].y - CD[idx].x * CD[i].y );
	}
	return abs(Sum)/2.0;
}
int main(void)
{
	int ans=0;
	cout.precision(1);
	cout << fixed;
	InputData();
	ans = Solve();	
	cout << ans*N << endl;
	return 0;
}
/*[4863][실전]참외 밭(중등)*/
