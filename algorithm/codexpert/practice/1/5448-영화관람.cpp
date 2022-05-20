#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s, e;
};
DATA A[MAXN + 10];
DATA B[MAXN + 10];
bool comp(DATA a, DATA b){
	return (a.e < b.e);
}
int Solve(){
	//1. 정의 
	int count=0;
	int cnt=0;//영화 관람 가능 편수 
	//2.영화시간이 1시간 미만이것들은 걸러내고 큐에 저장한다
    for (int i=0; i<N; i++){
        if((A[i].e - A[i].s)>=2){
			B[count++]=A[i];
		}
    }
	sort(B,B+count,comp);
	int end=B[0].e;
	cnt++;
	for(int i=1; i<count; i++){
		if(end <= B[i].s){
			cnt++;
			end=B[i].e;
		}
	}

	return cnt;
}
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
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
