#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[5000 + 10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}

void OutputData(){
    for (int i=0; i<N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    InputData();//입력 받는 부분
    
    //여기서부터 작성
    sort(A, A+N); 
    OutputData();//출력 하는 부분
    return 0;
}
