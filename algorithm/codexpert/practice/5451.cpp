#include <iostream>
#include <stack>
using namespace std;
#define MAXN ((int)1e5)
int N;//히스토그램수
int H[MAXN+10];//히스토그램 높이
bool InputData() {
    cin >> N;
    if (N == 0) return false;
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    return true;
}
int SolveN2(){
    long long max=0, area;
    for (int s=0; s<N; s++){
        int min_h=(int)1e9+10;
        for (int c=s; c<N; c++){
        if (min_h > H[c]) min_h = H[c];//낮은 높이 선택
          if (min_h == 0) break;
            area = min_h * (c - s + 1); 
           if (max < area) max = area;
         }   
      }   
    return max;
}
struct S {
	int h,n;//높이,인덱스
}; 
long long Solve(){
    long long maxarea = 0, area;
    stack<S>s;
    s = {};//stack init
    for (int i=0; i<N; i++){
        int n=i;//i번 직사각형의 초기 인덱스
        //1.스택에 저장된 높이가 i번 보다 높거나 같으면 제거
        while (!s.empty() && (s.top().h>= H[i])){
            n = s.top().n;//인덱스 뺏어오기
            area = (long long)s.top().h* (i-n);
            if (maxarea < area) maxarea = area;
            s.pop();
        }
        //2.i번 직사각형 스택에 저장
        s.push({H[i], n});
    }
    while(!s.empty()){
        area = (long long)s.top().h* (N - s.top().n);
        if (maxarea < area) maxarea = area;
        s.pop();
    }
    return maxarea;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans = -1;
    while(InputData()){//입력받는 부분

    ans=Solve();
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}
