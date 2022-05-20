/*[4881] A4: [1주차][01과-단순정렬][응용] 모범생*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 3e4)
int N;
struct Data{
	int id;
	int score;
};
struct Data d[MAXN+10];
void InputData(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> d[i].score;
		d[i].id=i+1;
	}
}
bool comp(struct Data c, struct Data f){
	if(c.score == f.score){
		return c.id < f.id;
	}else{
		return c.score > f.score;
	}
}
void Solve(){
	sort(d, d+N, comp);
	for(int i=0; i<N; i++)
		cout << d[i].score << ' ' ;
	for(int i=0; i<3; i++){
		cout << d[i].id << ' ';
	}
	cout << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
/*[4881] A4: [1주차][01과-단순정렬][응용] 모범생*/
