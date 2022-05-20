#include <iostream>
using namespace std;
#define MAXN ((int)5e4+10)
int N;//제품 수
struct st{
    int X, ID;//위치, 아이디
};
st A[MAXN];

st tmp[MAXN];
int nid[MAXN];
int check[MAXN];
int max_id_cnt;
void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i].X >> A[i].ID;
    }
}

void new_id(){
    for(int i=0;i<N;i++){
        int ni = A[i].ID % 50000;
        cout << "ni: " << ni << endl;
        for(int j=0;j<50000;j++){
            if(check[ni] == 0){
                max_id_cnt++;
                check[ni] = A[i].ID;
                cout << "ni: " << ni << ' ';
                cout << "max_id_cnt : " << max_id_cnt << ' ';
                cout << "check[ni]: " << check[ni] << ' ';
                cout << "before A[i].ID: " << A[i].ID << ' ';
                A[i].ID = ni;
                cout << "after A[i].ID: " << A[i].ID << endl;
                break;
            }else if(check[ni] == A[i].ID){
                A[i].ID = ni;
                break;
        }
            ni = (ni + 1) % 50000;
        }
    }
}

void sort(int s, int e){
    if(s >= e) return;
    int i=s,k=s,m=(s+e)/2, j=m+1;
    sort(s, m); sort(j, e);
    while((i<=m) && (j<=e)){
        if(A[i].X > A[j].X) tmp[k++] = A[j++];
        else tmp[k++] = A[i++];
    }
    while(i<=m) tmp[k++] = A[i++];
    while(j<=e) tmp[k++] = A[j++];
    for(i=s;i<=e;i++) A[i] = tmp[i];
}

void solve(){
    int i, j, cnt = 0, min = 1<<30;
    new_id();
    sort(0, N-1);
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
    solve();
    return 0;
}
