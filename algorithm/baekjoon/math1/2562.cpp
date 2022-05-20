#include <iostream>
#include <algorithm>
using namespace std;
struct D {
    int idx;
    int val;
};
struct D A[1000001];
bool comp(D a, D b){
    return (a.val < b.val);
}
int main(){
    int tmp;
    for(int i=0; i<9; i++){
        cin>>tmp;
        A[i].idx=i+1;
        A[i].val=tmp;
    }

    sort(A,A+9,comp);
    cout<<A[8].val<<endl;
    cout<<A[8].idx<<endl;

    return 0;
}