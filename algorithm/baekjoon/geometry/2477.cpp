/*baekjoon 2477 참외밭*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10010

struct Coordinate{
	int d;
	int length;
};

struct ST{
	int x;
	int y;
};

int	N;
struct Coordinate C[MAX];
struct ST CD[MAX];

void InputData(){
	//input data size
	cin >> N;
	//input data
	for(int i = 0; i < 5; i++){
		cin >> C[i].d >> C[i].length;
	}
}

void OutputData(){
	for( int i=0; i<N; i++){
	printf("\n");
	}
}

void ChangeCoord(){
	CD[0].x = 0;
	CD[0].y = 0;

	for(int i=1; i<6; i++){

		if( C[i].d == 1){
			CD[i].x -= C[i].length;
			cout << "x, y" << CD[i].x << CD[i].y << endl;
		}else if( C[i].d ==2 ){
			CD[i].x += C[i].length;
			cout << "x, y" << CD[i].x << CD[i].y << endl;
		}else if( C[i].d == 3){
			CD[i].y -= C[i].length;
			cout << "x, y" << CD[i].x << CD[i].y << endl;
		}else if( C[i].d ==4){
			CD[i].y += C[i].length;
			cout << "x, y" << CD[i].x << CD[i].y << endl;
		}

	}

}

int Solve(){
	int Sum=0;
	
	for(int i=0; i<6; i++){
		int idx;
		idx = (i+1) % 6;
		cout << "i, idx : " << i << idx << endl;
		Sum += (CD[i].x * CD[idx].y - CD[idx].x * CD[i].y );
	}
	return abs(Sum)/2.0;
}

int main()
{
	int ans=0;
	cout.precision(1);
	cout << fixed;
	InputData();
	ans = Solve();	
	cout << ans << endl;
	return 0;
}
/*baekjoon 2477 참외밭*/
