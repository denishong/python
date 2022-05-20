#include <iostream>
using namespace std;

#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];
int Stack[MAX + 10];
int Sp =0;

void InputData(){
    cin >> N;
    cin >> M[0];
    for(int i=1; i<N; i++){
        cin >> op[i] >> M[i];
    }
}

void Push( int d){
    Stack[++Sp] = d;
}

int Pop( ){
    return Stack[Sp--];
}

int Empty(){
    return (Sp == 0);
}

int Solve(){
    int Sum=0;
    Push(M[0]);

    for(int i=1; i<N; i++){

        switch(op[i]){

            case '+':
                Push( M[i] );
                break;

            case '-':
                Push( -M[i] );
                break;

                case '*':
                    Push( Pop()*M[i] );
                break;

            case '/':
                Push( Pop()/M[i] );
                break;
        }
    }
    while(!Empty()){
        Sum += Pop();
    }
    return Sum;
}


int main(){
	int ans = -1;
	InputData();//입력

	//여기서부터 작성
    ans = Solve();	
	cout << ans << endl;

	return 0;
}
