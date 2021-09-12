/*baekjoon 11651 좌표 정렬하기*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100000
int	N;
struct ST{
	int x, y;
};
struct ST Data[MAXN+10];

void InputData(){
	//input data size
    cin >> N; 
	//input data
    for( int i=0; i<N; i++ ){
    cin >> Data[i].x >>  Data[i].y; 
    }
}
bool comp(struct ST i, struct ST j){ 
	if (i.y < j.y) 
		return true;
	else if (i.y == j.y)
		return (i.x < j.x); 
	else 
		return false;
}
void Solve(){
    sort( Data, Data+N, comp );
	for( int i=0; i<N; i++){
		cout << Data[i].x << " " <<  Data[i].y << endl;
	}
}
int main()
{
	InputData();
	Solve();
	return 0;
}
/*baekjoon 11651 좌표 정렬하기*/
