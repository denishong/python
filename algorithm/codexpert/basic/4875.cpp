#include <iostream>
using namespace std;

#define MAXN (100)
int N;
int sol[MAXN + 10];
int queue[MAXN * MAXN + 10];
int Rp = 0, Wp = 0;

void InputData(){
    cin >> N;
}

void OutputData(){
    for (int i=0; i<N; i++){
        cout << sol[i] << ' ';
    }
        cout << endl;
}

void In_Queue(int d){
    queue[Wp++] = d;
}

int Out_Queue(){
    return queue[Rp++];
}

int Back_Queue(){
    return queue[Wp-1];
}

int Empty(){
    return Wp == Rp;
}

void Solve(){
    int i,j, cnt, r, k = 0;

    for( i = 0; i < N; i++) In_Queue(i+1);

    for(i = 0; i < N-1; i++) {
        cnt = Back_Queue() / 2;
        for( j=0; j < cnt; j++) {
            r = Out_Queue();
            In_Queue(r);
        }
        sol[k++] = Out_Queue();
    }
        sol[k++] = Out_Queue();
}
    
int main(){
    InputData();//입력
    //여기서부터 작성
    Solve();
    OutputData();//출력
    return 0;
}
