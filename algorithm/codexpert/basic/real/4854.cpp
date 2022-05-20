/*[4854][실전] 도서관*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e4)
int N;
struct DATA{
    int s,e;
};
DATA A[MAXN + 10];
void OutputData(){
    for(int i=0; i<N; i++){
        cout  << A[i].s << " " << A[i].e << endl;
    }
}
void InputData(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}
bool comp(struct DATA ca, struct DATA cb){return (ca.s < cb.s);}
void Solve(){
    int present=0, absent=0, s,e;
    //1.오름차순 정렬
    sort(A, A+N,comp);
    //2.있었던 시간이랑 없었던 시간 구하기 
    s = A[0].s; e = A[0].e;
    for(int i=1; i<N; i++){
        if( A[i].s > e){
            if(absent < (A[i].s -e) ) absent = A[i].s -e;
            if(present < (e -s) ) present = e -s;
            s = A[i].s; e = A[i].e;
         }else if(e < A[i].e){
			 e = A[i].e;
		}
	}
    if(present < (e -s) ) present = (e -s);
    cout << present << " " << absent << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[4854][실전] 도서관*/
