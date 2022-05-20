#include <bits/stdc++.h>
using namespace std;

int main(void){
    string a, temp;
    for(int i=0; i<9; i++){
       temp = '0' + i;
        a = temp + a;
    }
    cout << a;
    return 0;
}
