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
    int value, cnt=0, from=0;
    cout << N << endl;
    value = A[from];
    while (cnt < N){
        while (value == 0){
            from = (from + 1) % N;
            value = A[from];
            cout <<"from, value: " << from << " " << value << " "  << __LINE__ << endl;
        }
        cout <<"value, from, cnt:" << value << " " << from <<" " << cnt << " "  << __LINE__ << endl;
        sol[cnt] = value;
        cnt++;
        A[from] = 0;
        from = (value + from) % N;
        value = A[from];
        cout <<"from, value: " << from << " " << value  << " " << __LINE__ << endl;
    }
}

int main(){
    InputData();//  입력 함수

    //      코드를 작성하세요
    Solve();
    OutputData();//출력
    return 0;
}
