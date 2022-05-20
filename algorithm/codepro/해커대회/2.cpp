#include <iostream>
#include <vector>
using namespace std;
char str[100000 + 10];
char cmd[500000 + 10];
char sol[600000 + 10];

vector<char> v;
int it=0;
void insert(char ch){
    v.insert(it,ch);
}
void left(){
    if(!v.empty()) it--;
}
void right(){
    if(!v.empty()) it++;
}
void del(){
    if (!v.empty()) v.erase(it);
}
void PRT(){
    int i = 0;
    for (cur = head->next; cur != tail; cur = cur->next) sol[i++] = cur->ch;
        sol[i] = 0;
        cout << sol << endl;
}
void InputData(){
    cin >> str;
    cin >> cmd;
}
void solve(){
    vector<int>::iterator it;
    for (int i = 0; str[i]; i++) v.push_back(str[i]);
    it= v.begin() + 5;
    for (int i = 0; cmd[i]; i++){
       switch (cmd[i]){
       case 'B'://제거
           del();
           break;
       case 'L'://커서 왼쪽으로 이동
           line->left();
           break;
       case 'R'://커서 오른쪽으로 이동
           line->right();
           break;
       default://삽입
           line->insert(cmd[i]);
       }
   }
}
void OutputData(){
    line->PRT();
}
int main(){
   InputData();
   solve();
   OutputData();
   return 0;
}
