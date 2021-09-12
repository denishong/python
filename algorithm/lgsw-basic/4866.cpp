#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s, e;//시작시간, 종료시간
};
DATA A[MAXN + 10];


void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}

void PrintData(){
    for (int i=0; i<N; i++){
        cout << A[i].s << " " << A[i].e << endl;
    }
}


bool Comp(const DATA a, const DATA b) {
	return (a.e < b.e);
}


int Solve(){
	int cnt = 1;
	int e = A[0].e;
	for( int i =1; i<N; i++){
		if( e >= A[i].s ) continue;
		cnt++;
		e = A[i].e;
	}
	return cnt;
}

int main(){
    int ans;
    InputData();//입력
	sort(A, A+N, Comp);
	//여기서부터 작성
	ans = Solve();

    cout << ans << endl;//출력
    return 0;
}
