/*baekjoon 2108 통계학*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN  ((int)5e5+10)

int	N;
int Data[MAXN]; 
int A[MAXN+10];
struct MaxData{
	int cnt,val;
};
MaxData C[8000+10];
void InputData(){
    cin >> N;
    for(int i = 0; i < N; i++){
    	cin >> Data[i];
    }
}
int comp(struct MaxData a, struct MaxData b){
	if( a.cnt == b.cnt ){
		return a.val < b.val;
	}else{
		return a.cnt > b.cnt;
	}
}
int SortSecond(){
	int maxvalue=0, j=0;
	for(int i=0; i< 8010; i++){
		if(A[i] >0 ){
			if(i<=4000){
				C[j].val=i;
			}
			else{
				C[j].val=4000-i;
			}
			C[j].cnt=A[i];
			j++;
		}
	}
	sort(C, C+8010,comp);
	if(C[0].cnt == C[1].cnt){
		maxvalue= C[1].val;
	}else{
		maxvalue=C[0].val;
	}

	return maxvalue ;
}
void Solve()
{
	double sum=0;
	sort(Data, Data+N);
    for( int i=0; i<N; i++){
		sum += Data[i];
		if( Data[i] >=0){
			A[Data[i]]++;
		} else{
			A[4000-Data[i]]++;
		}
    }
	cout << (int) round(sum/N) << endl;
	cout << Data[N/2] << endl;
	cout << SortSecond() << endl;
	cout << abs(Data[0] - Data[N-1]) << endl;
}
int main()
{
	InputData();
	Solve();
	return 0;
}
/*baekjoon 2108 통계학*/
