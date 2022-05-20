#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  for(int i=0; i<N; i++){
    for(int k=0; k<i; k++){
      cout << " ";
    }
    for(int j=0; j<2*(N-i)-1; j++){
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
