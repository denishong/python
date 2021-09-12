#include <bits/stdc++.h>
using namespace std;

int T;
stack<char> s;
char input[51];
void InputData(){
    cin >> T;
}
void OutputData(){
    if(s.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    while(!s.empty())
        s.pop();
}
void Solve()
{
	int n=0,check=0;

    for(int j=0; j<T; j++){
        check = 0;
        cin >> input;

        for(int i=0; input[i]; i++){
            if ( input[i] == '(')
                s.push(input[i]);
            else if(i == 0 && input[i] == ')'){
                s.push(input[i]);
                break;
            }else if(i !=0 && input[i]  == ')' ){
                if( s.empty() ){
                    s.push(input[i]);
                }else{
                    if( s.top() == '(' )
                        s.pop();
                    else
                        s.push(input[i]);
                }
            }
        }
    OutputData();
    }
}
int main(){
    InputData();
    Solve();
    return 0;
}
