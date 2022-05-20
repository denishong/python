#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;//개수
int F[MAXN + 10];
int BsLower(int s, int e, int d){
    int sol=e;
    while (s<=e){
        int m=(s+e)/2;
		cout << "s,e,d,m:" << s << ' ' << e << ' ' <<d<<' ' << m << endl;
        if (F[m] >= d){
            sol=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return sol;
}
 
long long Solve(){
    long long sum = 0;
    sort(F, F+N);
    for (int i=1; i<N; i++){
        int min = (int)((F[i] * 9 + 10 - 1)/10);
		//cout <<"F[i], min:" << F[i] << ' ' <<min << endl;
        int index = BsLower(0, i, min);
        sum += i - index;
    }
    return sum;
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> F[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long ans = -1;

	InputData();// 입력받는 부분
	ans=Solve();// 여기서부터 작성
	cout << ans << "\n";// 출력하는 부분
	return 0;
}
