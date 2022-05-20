#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e7)
int N;
struct PACKET{
    int packet_no;
    int prior_level;
};
struct PACKET p[MAXN];
void InputData(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> p[i].packet_no >> p[i].prior_level;
    }
}
bool Comp(struct PACKET i, struct PACKET j){ 
    if( i.prior_level < j.prior_level)
        return true;
    else if( i.prior_level == j.prior_level)
        return (i.packet_no < j.packet_no);
    else
        return false;
}
void Solve(){
    sort(p, p+N, Comp);
    for(int i=0; i<N; i++){
        cout << p[i].packet_no << ' ';
    }
    cout << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
