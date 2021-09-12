/*[10828] 스택*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e6)
int N;

int main()
{
    char input[10];
    int val,count;
    stack<int> s;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> input;

        if (!strcmp("push", input) ){
            cin >> val;
            s.push(val);
        }else if(!strcmp(input, "pop")){
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
            }else{
                cout << "-1" << endl;
            }
        }else if(!strcmp(input, "size")){
            cout << s.size() << endl;
        }else if(!strcmp(input, "empty")){
            cout << s.empty() << endl;
        }else if(!strcmp(input, "top")){
            if(!s.empty())
                cout << s.top() << endl;
            else
                cout << "-1" << endl;
        }
    }
    return 0;
}
/*[10828] 스택*/
