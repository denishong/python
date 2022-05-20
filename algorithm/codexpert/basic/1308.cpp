#include <iostream>
using namespace std;

int N, M;
int A[10000+10];
void InputData(){
    cin >> N;
    for (int i=0 ; i<N ; i++){
        cin >> A[i];
    }
    cin >> M;
}
void Solve(){
    int s,e,mid, max=0,sum;
    for(int i=0; i<N; i++){
        if(max<A[i]) max=A[i];
    } 

    s=1,e=max;
    while(s<=e){
        mid=(s+e)/2;
        sum=0;
        for(int i=0; i<N; i++){
            if( A[i]>=mid) sum+=mid;
            else sum+=A[i];
        } 
       if(sum > M) e=mid-1;
       else s =mid+ 1;
    }
    cout << e << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
