/*[11053]가장 긴 증가하는 부분 수열3*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e6+10)
int N; 
int A[MAXN];
vector<int> v;
auto it = v.begin();
void InputData(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}
void Solve(){
    v.push_back(A[0]);
    for(int i=1; i<N; i++){
        if(v.back() < A[i] ) v.push_back(A[i]);
        else {
            it = v.begin();
			cout<<"it:"<<*it<<endl;
            it = lower_bound(v.begin(), v.end(), A[i]);
			cout<<"it aff:"<<*it<<endl;
            *it = A[i];
			cout<<"*it :"<<*it<<endl;
        } 
    }
    cout << v.size() << endl;
}
int main(){
    InputData();
    Solve();
    return 0;
}
/*[11053]가장 긴 증가하는 부분 수열3*/
