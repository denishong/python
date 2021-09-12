#include <iostream>
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

void Sort(){

    int i,j;
    for(i = 0; i<N-1; i++){
        for(j = i+1; j <N; j++) {

        if(A[i] > A[j] ){
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    }
}

int main(){
    InputData();//입력 받는 부분
    
    //여기서부터 작성
    Sort(); 
    OutputData();//출력 하는 부분
    return 0;
}
