#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int x[10]{1,2,3,4,5,6,7,8,9,10};

	int y[10];
	int v1=10;

	transform(x[0],x[9],y[0],y[9], [v1](int x) {return x+v1;});

	for(auto n:y)
		cout << n << endl;
}
