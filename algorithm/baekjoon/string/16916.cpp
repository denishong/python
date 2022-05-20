#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e7)
char P[MAXN+5];
char S[MAXN+5];
int main(){
  cin >> P >> S;
  if(strstr(P, S))
    cout << '1' << endl;
  else
    cout << '0' << endl;
  return 0;
}
