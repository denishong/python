#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
vector<int> v;
int main(){
    for(int i=1; i<=20; i++)
        v.push_back(i);
    int a, b;
    for(int i=0; i<10; i++){
        cin >> a >> b;
        while( a < b){
            swap(v[a-1], v[b-1]);
            a++;
            b--;
         }
    }
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
	return 0;
}
