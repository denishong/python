#include <iostream>
#include<algorithm>
using namespace std;
int N;//후보자수
string str[10000 + 10];//후보자 이름
int M;//투표참가인원
string name[100000 + 10];//투표용지에 써있는 이름
int score[100000 + 10];//점수

typedef struct {
    string name;
    int number, score;
}ST;
ST POOL[10000 + 10];


int comp_name(ST a, ST  b) {
    if( a.name< b.name){
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
bool complower(const ST POOL, string b){
	cout<<"aaa:"<<POOL.name<<' '<< b<<endl;
	return POOL.name==b;
}
int BinarySearch(int idx) {
    int s, e, m;
    s = 0;
    e = N - 1;
    
    while (s <= e) {
        m = (s + e) / 2;
        if (name[idx]> POOL[m].name) {
            s = m + 1;
        }
        else if (name[idx]< POOL[m].name) {
            e = m - 1;
        }
        else {
            return m;
        }
    }

    return -1;
}

void Solve() {
    int index = 0, i = 0,tmp;
    sort(POOL, POOL+N, comp_name);
	for(int i=0;i<N; i++)
		cout<<POOL[i].name<<' '<<POOL[i].number<<endl;
	
    for (i = 0; i < M; i++) {
        tmp = lower_bound(POOL,POOL+N,name[i],complower) - POOL;
		index=POOL[tmp].score;
		cout<<"tmp,index:"<<tmp<<' '<<index<<endl;
        if (index != -1) {
            POOL[index].score += score[i];
        }
    }

    sort(POOL, POOL+N, comp_score);
    for (int j = 0; j < 3; j++) {
      cout<< POOL[j].name<<' '<< POOL[j].score<<endl;
    }
}

void InputData() {
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>str[i];
        POOL[i].name= str[i];
        POOL[i].number = i;
        POOL[i].score = 0;
    }
	
    cin>>M;
    for (int i = 0; i < M; i++) {
        cin>> name[i] >>score[i];
    }
}

int main() {
    InputData();
    Solve();
    return 0;
}
