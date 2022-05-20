/**
 * 백준 2003: 수들의 합 2
 *
 * 기본적인 two pointers algorithm
 * 
 * N 개의 수로 된 수열 A[1], A[2], ..., A[N]이 있다. 
 * i 번째 수부터 j 번째 수까지의 합 이 M 이 되는 경우의 수를 구하시오
 * 
 * 맨날 나오는 문제입니다.
 */

#include <iostream>
using namespace std;
const int MAX_SIZE = 10000;
int n,m;
int an[MAX_SIZE];

void Solve(){
    int sum=0,count = 0;
    int s = 0, e = 0;
    while (s <= e && e <= n) {
        if (sum >= m) {
            if (sum == m)
                ++count;
            sum -= an[s++];
        }else {
            sum += an[e++];
            cout <<"s,e,sum,an[end++]:" <<s<<' '<<e<<' '<<sum<<' '<<an[e]<<endl;
        }
    }

    cout << count << '\n';
}
void InputData(){
    // 1 <= n <= 10,000
    cin >> n;

    // 1 <= M <= 300,000,000
    cin >> m;

    // 1 <= an[i] <= 30,000
    for (int i = 0; i < n; ++i) {
        cin >> an[i];
    }
}
int main() {
	InputData();
	Solve();
	return 0;
}
/*
10 5
1 2 3 4 2 5 3 1 1 2
start,end,sum,an[end++]:0 1 1 2
start,end,sum,an[end++]:0 2 3 3
start,end,sum,an[end++]:0 3 6 4
start,end,sum,an[end++]:2 4 7 2
start,end,sum,an[end++]:3 5 6 5
start,end,sum,an[end++]:4 6 7 3
start,end,sum,an[end++]:6 7 3 1
start,end,sum,an[end++]:6 8 4 1
start,end,sum,an[end++]:6 9 5 2
start,end,sum,an[end++]:7 10 4 0
start,end,sum,an[end++]:7 11 4 0
3
*/
