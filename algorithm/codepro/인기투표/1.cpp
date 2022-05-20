#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN ((int) 1e4+10)
int N,M;
char str[MAXN][21];
char name[MAXN][21];
int score[MAXN];

struct DATA{
    int id, score;
};
bool comp(struct DATA a, struct DATA b){
    if(a.score  > b.score) return true;
    else if(a.score == b.score){
        if(a.id < b.id) return true;
        else return false;
    }
    return 0;
}
void Solve(void){
    struct DATA data[MAXN];
    for(int i=0; i<N; i++){
        data[i].id = i;
        data[i].score = 0;
        for(int j=0; j<M; j++){
            if(strcmp(str[i], name[j])) continue;
            data[i].score += score[j];
        }
    }
    sort(data, data+N, comp);
    for(int i=0; i<3; i++){
        cout << str[data[i].id] << ' ' << data[i].score << endl;
    }
}
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

int main(void){
    InputData();
    Solve();
    return 0;
}
