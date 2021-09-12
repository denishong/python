#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
int M;
char str[MAXN+10];
void InputData(){
	int i;
	cin >> M;
	cin >> str;
	for(i=0;str[i];i++);
	str[i]=' '; str[i+1]=0;
}
void Solve(void){
	int count=1;
	for(int i=1; str[i]; i++){
		if(str[i] != str[i-1]){
			if(count>=M){
				cout << str[i-1] << '(' << count << ')';
			}else{
				for(int j=0; j<count; j++){
					cout << str[i-1];
				}
			}
			count=1;
		}else{
			count++;
		}
	}
	cout << endl;
}
int main(void){
	InputData();
	Solve();
	return 0;
}
