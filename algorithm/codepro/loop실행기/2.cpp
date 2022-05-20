#include <iostream>
using namespace std;
#define MAXN ((int) 1e2+1)
char loop[MAXN];
void InputData(void){
    cin >> loop;
}
char* Solve(char* s){
    char* p=s;
    int cnt_loop = *(s+1)-'0';
    cout << "p: " << p << endl;
    while(cnt_loop--){
        p = s+2;
        cout << "while p: " << p << endl;
        while(*p != '>'){
            if(*p == '<'){
                p = Solve(p);
            }else{
                cout << *p;
            }
            p++;
        }
    }
    cout << "return p: " << p << endl;
    return p;
}
int main(void){
    InputData();
    Solve(loop);
    return 0;
}
