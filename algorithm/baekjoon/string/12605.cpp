#include <bits/stdc++.h>
using namespace std;
int N;
string Solve(string sentence){
    int size = sentence.size();
    string ans;
    string tmp;
    vector <string> s;
    for(int i=0; i<size; i++){
        tmp += sentence[i];
        if(sentence[i] == ' ' || i == size-1){
            s.push_back(tmp);
            tmp = "";
        }
    }
    for(int i = s.size() - 1; i >= 0; i--){
        ans += s[i];
        if(i == s.size() - 1) ans += ' ';
    }
    return ans;
}
void InputData(){
    cin >> N;
    cin.ignore();
    for(int i=1; i<=N; i++){
        string sentence;
        getline(cin, sentence);
        sentence = Solve(sentence);
        cout << "Case #" << i << ": " << sentence << endl;
    }
}
int main()
{
    InputData();
    return 0;
}
