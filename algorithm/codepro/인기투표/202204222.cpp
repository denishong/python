#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN ((int) 1e4+10)
#define MAXM ((int) 1e4+10)
int N,M;
char str[MAXN][21];
char name[MAXM][21];
int score[MAXM];
int idx[MAXM];

struct DATA{
	char name[21];
    int id, score;
};

struct DATA A[10000];
bool comp(DATA a, DATA b){
    if( strcmp(a.name, b.name) >0 ) return true;
    else return false;
}
bool compdata(struct DATA a, struct DATA b){
    if(a.score > b.score) return true;
    else if(a.score == b.score){
        if(a.id < b.id) return true;
        else return false;
    }
    return 0;
}
int bslow(int s, int e, int d){
    int m, sol=-1,r;
    while(s<=e){
        m=(s+e)/2;
      //cout << "s : " << s << " e: " << e  << " d: " << d <<  " m: " << m << endl;
        r=strcmp(name[idx[m]], str[d]);
		strcpy(name[idx[m]],str[d]);
        if(r==0){
            sol=m; e=m-1;
        }else if(r>0) e=m-1;
        else s=m+1;
    }
    return sol;
}
void Solve(void){
    sort(A, A+N, comp);

    for(int i=1; i<=N; i++){
        cout<< A[i].id<<' '<<A[i].name<<' ';
	}
    for(int i=1; i<=N; i++){
		if(strcmp(A[i].name,A[i+1].name)==0){

		}else{

		}
    }
}
void InputData(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> str[i];
		strcpy(A[i].name,str[i]);
		A[i].id=i;
    }
}
int main(void){
    InputData();
    Solve();
    return 0;
}
