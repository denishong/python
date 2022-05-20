#include <bits/stdc++.h>
using namespace std;
int N;
char x[1000];
void recur(int a)
{
	if(a > 0){
		recur(a-1);
	}
}
void Solve(){
    int n;
    int cnt = strlen(x);
    for(int i=0; i<cnt; i++){
        if(x[i] >= '1' &&  x[i] <= '9'){
          n = atoi(x);
          cout << x[i] ;
        }
    }
}
int main(void)
{
    int N;
    char tmp[100]="";
    cin >> x;

	Solve();
    return 0;
}
