#include <iostream>
#include <algorithm>
using namespace std;
int D[1000001];
int main(){
    int N;
    cin>>N;

    for(int i=0; i< N; i++)
        cin>>D[i];

    sort(D,D+N);
    cout<<D[0]<<' '<<D[N-1];
    return 0;
}