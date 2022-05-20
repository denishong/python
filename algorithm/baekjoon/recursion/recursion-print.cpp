#include <bits/stdc++.h>
using namespace std;
int N;
char x[100]="abc";
char tmp[100]="";
void recur(int a)
{
    if(a > 0){
        recur(a-1);
        printf("%s", x);
    }
}
int main(void)
{
    int N;
    cin >> N >> x;

    recur(N);
    return 0;
}
