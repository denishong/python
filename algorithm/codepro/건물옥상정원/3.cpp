#include <iostream>
#include <stack>
using namespace std;
#define MAXN ((int)8e4 + 10)
int N;
int H[MAXN];

void Input_Data(void){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> H[i];
  }
}
void Solve(){
  long long sum = 0;
  stack<int> s;
  for(int i=0; i<N ; i++){
    while(!s.empty() && !(H[i] < s.top())){
    cout << "H[i], stack[sp] " << H[i] << ',' << s.top() << endl;
      s.pop();
    }
    cout << "stack size:" << s.size() << endl;
    sum += s.size();
    s.push( H[i] );
  }
  cout << sum << endl;
}
int main(){
  Input_Data();
  Solve();
  return 0;
}
