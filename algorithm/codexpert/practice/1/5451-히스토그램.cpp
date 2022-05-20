#include <iostream>
#include <stack>
using namespace std;
#define MAXN ((int)1e5)
int N;//히스토그램수
int H[MAXN+10];//히스토그램 높이
#define s64 long long
struct S{
	int h,n;
};
s64 Solve(){
	s64 maxarea=0, area;
	stack<S>s;
	for(int i=0; i<N; i++){
		int n=i;//i번 직사각형의 초기 인덱스 
		//1.스택에 저장된 높이가 i번 보다 높거나 같으면 제거 
		while(!s.empty() && (s.top().h >=H[i])){
			n=s.top().n; //인덱스 뺏어오기 	
			area=(s64)s.top().h*(i-n);
			if(maxarea<area) maxarea=area;
			s.pop();
		}
		//2.i번 직사각형 스택에 저장 
		s.push({H[i],n});
	}
	while(!s.empty()){
		area=(s64)s.top().h*(N-s.top().n);
		if(maxarea<area) maxarea=area;
		s.pop();
	}

	return maxarea;
}
bool InputData() {
	cin >> N;
	if (N == 0) return false;

	for (int i=0; i<N; i++){
		cin >> H[i];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long ans = -1;
	//while(InputData()){//입력받는 부분
	InputData();
		ans=Solve();//여기서부터 작성
		cout << ans << "\n";//출력하는 부분
	//}
	return 0;
}
