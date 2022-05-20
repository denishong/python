#include <iostream>
using namespace std;

int N;
int A[30 + 10];
int sol[30 + 10];

void InputData(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
}
void OutputData(){
    cout << N << endl;
    for(int i=0;i<N;i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}
void Solve(){
    int i, j, index = 0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(sol[index] == 0) break;
            index = (index + 1) % N;
            cout << "i: " << i << "index : " << index << "LINE : " <<  __LINE__  << endl;
        }
        sol[index] = A[i];
        index = (index + A[i]) % N;
            cout << "i : " << i << " index :  " << index << "A[i] : " << A[i] ;
            cout << " LINE : " <<  __LINE__  << endl;
    }
}
int main(){
    InputData();
    Solve();
    OutputData();
    return 0;
}
