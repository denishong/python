#include <bits/stdc++.h>
using namespace std;

void recursive(int a)
{
	if(a == 1000)
	return;
	else
        cout << "recursive : " << a << endl;
    recursive(a+1);
}

int main()
{
    int repeat;
    cin >> repeat;

	recursive(repeat);
    return 0;
}
