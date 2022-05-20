#include <iostream>
using namespace std;
#define MAXN ((int)8e4)
int H[MAXN+10];
int N;
void InputData(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
}
long long Solve(){
  long long sum=0;
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      if(H[i] > H[j]){
        sum++;
      }else{break;}
    }
  }
  return sum;
}
int main() {
  InputData();
  cout << Solve() << endl;
  return 0;
}
