#include <iostream>

using namespace std;

#define MAX_LOOP    (100)
#define MAX_ARR     (MAX_LOOP+1)

char loop[MAX_ARR];

char* Solve(char* s){
    int cnt;
    char* p;
    p=s;
    cnt=*(s+1)-'0';//반복 회수 
    while(cnt--){
        cout<<cnt<<endl;
        p=s+2;
        while(*p!='>'){
            cout<<*p;
            p++;
        }
    }
    return p;    
}
void InputData(void){
    cin >> loop;
}

int main(void)
{
    InputData();
    Solve(loop);
    return 0;
}
