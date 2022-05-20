#include <iostream>
using namespace std;

int N;//자료 개수
struct ST{
    int id, score;//아이디, 점수
};
ST A[30000 + 10];//자료

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].score;
        A[i].id = i+1;
    }
}

void OutputData() {
    for (int i = 0; i < 3; i++) {
        cout << A[i].id << " ";
    }
    cout << endl;
}

void Sort(int s, int e){

    int i,j,temp;
    for( i = s; i<s +3; i++){
        for( j =i+1; j<=e; j++){
            if( (A[i].score < A[j].score) ||
                ((A[i].score == A[j].score) && (A[i].id > A[j].id)) ){
                struct ST temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

}

int main() {
	InputData();//입력
	//작성
	Sort(0, N-1);
	OutputData();
	return 0;
}
