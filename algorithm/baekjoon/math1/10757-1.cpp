#include <bits/stdc++.h>
using namespace std;
string A,B,SUM;
char res[10003];
int carry = 0;
int length = 0;

void InputData(){
    cin >> A >> B;
}
void Solve(){
    int sum = 0, temp;
    char chA, chB, remain;
    int sizeA = A.size();
    int sizeB = B.size();

    if( sizeA > sizeB){
        length = sizeA;
    }else{
        length = sizeB;
    }

    for(int i=1; i<=length; i++){
        if( sizeA >= i)
            chA = (A[sizeA - i]-'0');
        else
            chA = 0;

        if( sizeB >= i)
            chB = (B[sizeB - i]-'0');
        else
            chB = 0;

        temp = chA + chB + carry; 
        carry = temp /10;
        remain = temp % 10 + '0';
        SUM = remain + SUM;
    }
    if( carry == 1)
        SUM = static_cast<char>(carry + '0') + SUM;
    cout << SUM << endl;
}

int main(){
    InputData();
    Solve();
    return 0;
}
