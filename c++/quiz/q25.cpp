#include <iostream>
using namespace std; 


int main()
{
	int x[3]={1,2,3,};
	
	auto a1=x[0];
	//decltype(x[0]) d1;
	auto a2=x;
	decltype(auto) d2=x;
}
