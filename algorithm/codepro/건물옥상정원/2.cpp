#include <iostream>
using namespace std;
#define MAXN ((int)8e4 + 10)
int N;
int H[MAXN];
int stack[MAXN];

void Input_Data(void){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> H[i];
  }
}
void Solve(){
  int sp = 0;
  long long sum = 0;
  for(int i=0; i<N ; i++){
    while(sp > 0){
    cout << "H[i], stack[sp] " << H[i] << ',' << stack[sp] << endl;
      if(H[i] < stack[sp]) break;
      sp--;
    }
    cout << "sp:" << sp << endl;
    sum += sp;
    stack[++sp] = H[i];
  }
  cout << sum << endl;
}
int main(){
  Input_Data();
  Solve();
  return 0;
}
