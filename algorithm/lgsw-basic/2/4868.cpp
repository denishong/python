/*[4868] A6: [1주차][02과-퀵정렬][기본] 오름차순 정렬 (퀵정렬)*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 3e4)
int N;
int d[MAXN+10];
void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> d[i];
	}
}
bool comp(int c, int f){
	return c < f;
}
void Solve(){
	sort(d, d+N, comp);
	for(int i=0; i<N; i++)
		cout << d[i] << ' ' ;
	cout << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
/*[4868] A6: [1주차][02과-퀵정렬][기본] 오름차순 정렬 (퀵정렬)*/
