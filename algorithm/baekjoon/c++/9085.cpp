#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,N,x,total=0;
    cin >>T;
    for(int k=0; k<T; k++){
        total=0;
        cin >> N;
        for(int i=0; i<N; i++){
        cin >> x;
        total += x;
        }
    cout << total << endl; 
    }
    return 0;
}
