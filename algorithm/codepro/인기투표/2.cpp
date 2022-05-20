#include <iostream>
#include <cstring>
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
    int id, score;
};
void InputData(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str[i];
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> name[i] >> score[i];
    }
}
bool comp(int a, int b){
    //cout << " a: " << a << ' ' << " b: " << b << ' ' <<  name[idx[a]] << endl;
    if( strcmp(name[a], name[b]) <=0 ) return true;
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
    struct DATA data[MAXN];
    int low;
    for(int i=0; i<M; i++){
        idx[i] = i;
    }
    sort(idx, idx+M, comp);
    for(int i=0; i<N; i++){
        data[i].id=i; data[i].score=0;
        low = bslow(0, M-1, i);
        if( low < 0) continue;
        for(int j=low; (j<M) && !strcmp(str[i], name[idx[j]]); j++){
            data[i].score += score[idx[j]];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=i+1; j<N; j++){
            if( (data[i].score < data[j].score) ||
             ((data[i].score == data[j].score) && (data[i].id > data[j].id))){
                 struct DATA tmp = data[i]; data[i] = data[j]; data[j] = tmp;
            }
        }
    }
    for(int i=0; i<3; i++){
        cout << str[data[i].id] << ' ' << data[i].score << endl;
    }
}
int main(void){
    InputData();
    Solve();
    return 0;
}
