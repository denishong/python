#include <iostream>
#include<algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;
int N;//후보자수
char str[10000 + 10][20 + 10];//후보자 이름
int M;//투표참가인원
char name[100000 + 10][20 + 10];//투표용지에 써있는 이름
int score[100000 + 10];//점수

typedef struct {
    char name[20 + 10];
    int number, score;
}ST;
ST POOL[10000 + 10];


int comp_name(ST a, ST  b) {
    if( strcmp(a.name, b.name) <0){
			return true;
		}else{
			return false;
		}
}
int comp_score(ST a, ST b) {
    if (b.score == a.score) {
        return (a.number < b.number);
    }

    return (a.score > b.score);
}

int BinarySearch(int idx) {
    int s, e, m;
    s = 0;
    e = N - 1;
    
    while (s <= e) {
        m = (s + e) / 2;

        if (strcmp(name[idx], POOL[m].name) > 0) {
            s = m + 1;
        }
        else if (strcmp(name[idx], POOL[m].name) < 0) {
            e = m - 1;
        }
        else {
            return m;
        }
    }

    return -1;
}

void Solve() {
    int index = 0, i = 0;
    sort(POOL, POOL+N, comp_name);
	
    for (i = 0; i < M; i++) {
        index = BinarySearch(i);
        if (index != -1) {
            POOL[index].score += score[i];
        }
    }

    sort(POOL, POOL+N, comp_score);
    for (int j = 0; j < 3; j++) {
      printf("%s %d\n", POOL[j].name, POOL[j].score);
    }
}

void InputData() {
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>str[i];
        strcpy(POOL[i].name, str[i]);
        POOL[i].number = i;
        POOL[i].score = 0;
    }
	
    cin>>M;
    for (int i = 0; i < M; i++) {
        cin>> name[i] >>score[i];
    }
}

int main() {
    InputData();//	입력 함수
    Solve();
    return 0;
}
