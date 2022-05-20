#include <iostream>
using namespace std;
int N;
int H[10000];
void Solve(){
    int s, e, m,sol=0;
    s=0; e=1000;
    while(s<=e){
        m=(s+e)/2;
        cout << "s,e " << s << ' ' << e << endl;
        if(N>=H[m]){
            sol=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    cout << sol << endl;
}
void InputData(){
    cin >> N;
    for(int i=0; i<1000; i++){
        H[i]=i;
    }
}
int main(){
    InputData();
    Solve();

    return 0;
}
