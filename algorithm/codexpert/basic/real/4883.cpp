/*[실전][4883]빌딩*/
#include <bits/stdc++.h>
using namespace std;
int N;
int lookup[] = { 0, 1, 2, 3, 0, 4, 5, 6, 7, 8};
void InputData(){
    cin >> N;
}
int Solve(){
    int real =0, digit=1;
    while(N){
        real += lookup[N%10] * digit;
        N /= 10;
        digit *= 9;
    }
    return real;
}
int isPossible(int x){
	x%4
int Solve1(){
	int cnt=0;
	for(int i=1; i<=N; i++){
		if(isPossible(i)) cnt++;
	}
	return cnt;
}
int main(){
    int ans = -1;
    InputData();
    ans = Solve1();
    cout << ans << endl;
    return 0;
}
/*[실전][4883]빌딩*/
