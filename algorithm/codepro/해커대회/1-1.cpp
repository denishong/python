#include <iostream>
#include <vector>
#include <stack>

using namespace std;

char str[100000 + 10];//초기 문자열
char cmd[500000 + 10];//명령어 문자열

void InputData(){
    cin >> str;
    cin >> cmd;
}
void Solve(){
    vector<char> lv;
    stack<char> rs;
    for(int i=0; str[i]; i++) lv.push_back(str[i]);
    
    for(int i=0; cmd[i]; i++){
        switch (cmd[i]){
            case 'B': //제거 
                if(!lv.empty()) lv.pop_back();  
            break;
                
            case 'L': //커서 왼쪽으로 이동 
                if(!lv.empty()) {
                    rs.push(lv.back());
                    lv.pop_back();
                }   
            break;
                
            case 'R': //커서 오른쪽으로 이동 
                if(!rs.empty()) {
                    lv.push_back(rs.top());
                    rs.pop();
                }   
            break;
            
            default://삽입
                lv.push_back(cmd[i]);
            break;
        }
    }
    
    for(int i=0; i<lv.size(); i++){
        cout << lv[i];
    }
    while(!rs.empty()){
        cout << rs.top();
        rs.pop();
    }
}
int main(){
    InputData();
    Solve();
    return 0;
}
