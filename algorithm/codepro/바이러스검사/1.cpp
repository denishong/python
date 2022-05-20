nclude <iostream>
#include <algorithm>
using namespace std;

int N; // 실행 코드의 데이터 개수
int M; // 바이러스의 데이터 개수
int A[20000 + 10]; // 실행 코드의 데이터
int B[10 + 10]; // 바이러스의 데이터
int P[10 + 10];
int first =1;
int sol; // 정답

void InputData(void)
{
    int i;
    cin >> N >> M;
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (i = 0; i < M; i++) {
         cin >> B[i];
    }
}
int Find(int start)
{
    int i;
    int min;
	
    if(first == 1){
        first = 0;
        sort(B,B+M);
        min = B[0];
        for(int i=0; i<M; i++)
            B[i]= B[i] - min;
    }
	
    for(int i=0; i<M; i++){
        P[i] = A[start+i];		
    }
	
    sort(P, P+M);
    min = P[0];
    for(int i=0; i<M; i++)
        P[i]= P[i] - min;
	

    for (i = 0; i < M; i++) {
        if (B[i] != P[i]) return 0;
    }
    return 1;
}

void Solve(void)
{
    for (int i = 0; i <= N - M; i++) {
        sol += Find(i);
    }
    cout << sol << endl;
}

int main(void)
{
    InputData();
    Solve();
    return 0;
}
