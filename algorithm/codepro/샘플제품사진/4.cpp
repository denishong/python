#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)5e4+10)
int N;
struct st{
    int X, ID;
};
st A[MAXN];

st tmp[MAXN];
int nid[MAXN];
int check[MAXN];
int max_id_cnt;
int bid;
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
	sort(A,A+N,comp_ID);
	bid=A[0].ID;
	A[0].ID=0;
	max_id_cnt = 1;
	
	for(int i=1;i<N;i++){
		if(bid== A[i].ID){
			A[i].ID=A[i-1].ID;
		}else{
			bid=A[i].ID;
			A[i].ID=A[i-1].ID+1;
			max_id_cnt++;
		}
	}
}
void solve(){
    int i, j, cnt = 0, min = 1<<30;
    new_id();
    sort(A,A+N,comp_X);
    for(i=0;i<MAXN;i++) check[i] = 0;
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
