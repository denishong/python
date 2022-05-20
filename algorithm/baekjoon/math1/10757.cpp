#include <bits/stdc++.h>
using namespace std;
char A[10002];
char B[10002];
char res[10003];
int carry = 0;
int length = 0;

void InputData(){
    cin >> A >> B;
}
void reverse(char arr[]){
    int len = strlen(arr);
    for(int i=0; i<len/2; i++){
        char temp = arr[i];
        arr[i] = arr[len -i -1];
        arr[len -i -1] = temp;
    }
}
void Solve(){
    int sum = 0, temp;
    char chA, chB;
    reverse(A);
    reverse(B);
    int sizeA = strlen(A);
    int sizeB = strlen(B);

    if( sizeA > sizeB){
        length = sizeA;
    }else{
        length = sizeB;
    }

    for(int i=0; i<length; i++){
        if( sizeA >= i)
            chA = (A[i]-'0');
        else
            chA = 0;

        if( sizeB >= i)
            chB = (B[i]-'0');
        else
            chB = 0;

        sum = chA + chB + carry; 
        carry = sum /10;
        res[i] = sum % 10 + '0';
    }
    if( carry == 1)
        res[length] = '1';
    reverse(res);
    cout << res << endl;
}

int main(){
    InputData();
    Solve();
    return 0;
}
