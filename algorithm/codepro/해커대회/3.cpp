#include <iostream>
#include <deque>
#include <stack>
using namespace std;

char str[100000 + 10];//초기 문자열
char cmd[500000 + 10];//명령어 문자열

void InputData(){
    cin >> str;
    cin >> cmd;
}
void Solve(){
    deque<char>q;
    stack<char>s;

    for(int i=0; str[i]; i++){
        q.push_back(str[i]);
    }
    for(int i=0; cmd[i]; i++){
        switch(cmd[i]){
            case 'B':
                if(!q.empty()){
                    q.pop_back();
                }
            break;

            case 'R':
                if(!s.empty()){
                    q.push_back(s.top());
                    s.pop();
                }
            break;

            case 'L':
                if(!q.empty()){
                    s.push(q.back());
                    q.pop_back();
                }
            break;

            default:
                q.push_back(cmd[i]);
            break;
        }
    }

    while(!q.empty()){
        cout << q.front();
        q.pop_front();
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}
int main(){
    InputData();//	입력 함수
    Solve();
    return 0;
}
