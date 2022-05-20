#include <bits/stdc++.h>
using namespace std;

void recur(int a)
{
	if(a > 0){
		recur(a-1);
		printf("out: %d\n", a);
		recur(a-2);
	}
}

void recur2(int a)
{
	if(a > 0){
		recur2(a-2);
		printf("out: %d\n", a);
		recur2(a-1);
	}
}
void recur3(int a)
{
	if(a > 0){
		recur3(a-1);
		printf("out: %d\n", a);
	}
}

int main(void)
{
    int x;
    cin >> x;

	recur3(x);
    return 0;
}
