#include <iostream>
#include <algorithm>
using namespace std;

int N;//제품 수
struct st{
    int X, ID;//위치, 아이디
};
st A[50010];

st tmp[50010];
int nid[50010];
int check[50010];
int max_id_cnt;

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i].X >> A[i].ID;
    }
}
bool comp_ID(struct st i, struct st j){
    return (i.ID < j.ID);
}
bool comp_X(struct st i, struct st j){
    return (i.X< j.X);
}

void new_id(){
    for(int i=0;i<N;i++){
        int ni = A[i].ID % 50000;
        for(int j=0;j<50000;j++){
            if(check[ni] == 0){
                max_id_cnt++;
                check[ni] = A[i].ID;
                A[i].ID = ni;
                break;
            }
            else if(check[ni] == A[i].ID){
                A[i].ID = ni;
                break;
            }
            ni = (ni + 1) % 50000;
        }
    }
}

void Solve(){
    int i, j, cnt = 0, min = 1<<30;
    new_id();
    sort(A,A+N,comp_X);
    for(i=0;i<50000;i++) check[i] = 0;
    i=j=0;
    for(;;){
        while((i<N) && (max_id_cnt > cnt)){
            if(check[A[i].ID]++ == 0) cnt++;
            i++;
        }
        if(max_id_cnt != cnt) break;
        while(check[A[j].ID]>1){
            check[A[j].ID]--; j++;
        }
        if(min > A[i-1].X - A[j].X) min = A[i-1].X - A[j].X;
        cnt--; check[A[j].ID]=0; j++;
    }
    cout << min << endl;
}

int main(){
    InputData();
    Solve();
    return 0;
}
