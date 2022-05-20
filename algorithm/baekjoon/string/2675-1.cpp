#include <iostream>
using namespace std;
int T,R;
string S;

int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> R >> S;
        for(int j=0; j<S.size(); j++){
            for(int r=0; r<R; r++){
                cout << S[j];
            }
        }
        cout << endl;
    }
    return 0;
}
