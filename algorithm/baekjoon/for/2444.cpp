#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  for(int i=1; i<=2*N-1; i++){
    for(int k=1; k<=N-i; k++){
      cout << " ";
    }
    for(int j=1; j<=2*i-1; j++){
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
