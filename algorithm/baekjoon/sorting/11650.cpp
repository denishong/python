/*baekjoon 11650 좌표 정렬하기*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100000
int	N;
struct ST{
	int x, y;
};
struct ST XYdata[MAXN+10];

void InputData(){
	//input data size
    scanf("%d", &N);
	//input data
    for( int i=0; i<N; i++ ){
    scanf("%d %d", &XYdata[i].x, &XYdata[i].y );
    }
}
void OutputData(){
	for( int i=0; i<N; i++){
		printf("%d %d", XYdata[i].x, XYdata[i].y);
	printf("\n");
	}
}
bool comp(struct ST i, struct ST j){ 
	if (i.x < j.x) 
		return true;
	else if (i.x == j.x)
		return (i.y < j.y); 
	else 
		return false;
}
int main()
{
	InputData();
	sort( XYdata, XYdata+N, comp );
	OutputData();
	return 0;
}
/*baekjoon 11650 좌표 정렬하기*/
