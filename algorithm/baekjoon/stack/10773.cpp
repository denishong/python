#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void InputData(){
    int K,val;
    cin >> K;

    for(int i=0; i<K; i++){
        cin >> val;
        if(val > 0)
            s.push(val);
        else if(val == 0)
            s.pop();
    }
}
void Solve(){
    int total=0;
    while(!s.empty())
    {
        total += s.top();
        s.pop();
    }
    cout << total << endl;
}
int main()
{
    InputData();
    Solve();
    return 0;
}
